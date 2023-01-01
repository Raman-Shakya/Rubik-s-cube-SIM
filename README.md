# Rubik's cube simulator and AI
---

## Download
```bash
git clone "https://github.com/Raman-Shakya/Rubik-s-cube-SIM"
cd Rubik-s-cube-SIM
```

## Start
```bash
g++ main.cpp -o main
./main
```
---

## SIM:
### How it works:
1. Cube class has a grid property which saves the cube state in the net view (char grid[9][13]) (characters with sticker colors "WYBGRO"). This is inefficient as there are 54*size_of(char) which is left unused and is initialized with " "
2. It uses 2 steps to turn a face
    1. rotate all the pieces around the face clockwise 2 times so that edges don't conflict with corners. (optimization: rotate edges and corners separately so that rotation can be done just once)
    1. rotate all the remaining pieces (actual cube is divided into pieces not stickers so, 1 turn changes not 9 but 20 stickers)
3. For double and anti-clockwise turns:
    - double turns: do the clockwise turn 2 times
    - anti-clockwise turn: do the clockwise turn 3 times
---


## AI
### How it works
Total combination in a Rubik's cube is HUGEE. This makes it very hard to brute-force and solve the cube. You can imagine this as a Graph where from a Node/State you can get to 18 other states (including 3 variants of ```R, U, L, D, F, B``` moves). If we were to brute-force to God's number **20** which is the maximum number of moves required to reach any state from any other state in a 3x3 rubik's cube, it would mean to search through **18<sup>20</sup>=1.2748236*10<sup>25</sup>** states which is not feasible to do with even a very powerful computer.
To solve this issue, we can divide the process to different sub-groups which is easier and require less moves to reach. Most notable algorithms are the **Kociemba Algorithm and Thistlethwaite's Algorithm**. However, here I divided the steps as the following:

1. **EO (Edge Orientation)**: This helps to remove F and B move variants later in the solve which reduces the width of the tree-graph. We can use just ```<R,U,D,L,F,B>``` moves with depth of 7 to solve the EO. We can use DFS or BFS to find the state (here I used DFS)
<br>
2. **CROSS**: Unfortunately solving cross directly was too slow for me, so I solved the daisy using ```<R,L,U,D,R',L',U',D',R2,L2>``` moves (following beginners method) (used DFS with depth of 7) and used DFS with depth of 4 with move configuration ```<R2> <D> <U, U', U2>``` to solve the rest of the cross.
<br>
3. **BELT**: This is a weird part in the solve. Solving 1 F2L pair at a time was time consuming so I deviced a different method to solve belt first, To do this, I used following move configuration and depth of 5 ```init_move=<R, R', L, L'> <,D,D',D2> inverse(init_move)```
<br>
4. **F2L**: For F2l (First 2 Layers) I moved the D layer until I found a corner in the DFR corner and used 1 in 3 algorithms to solve it relative to the edges:
    * if white is in bottom right: ```L' U L D' L' U' L```
    * if white is in bottom front: ```L U2 L' D2 L U2 L'```
    * if white is in the bottom :  ```R' D' R D R' D' R D R' D' R```

    in the first layer with setup moves ```<,U,U',U2>``` after solving all the bottom corners having white sticker, I checked for any in the top layer but relatively unsolved, I again used ```L U2 L' D2 L U2 L'``` algorithm to take it to bottom layer and using recursion solved the rest of the F2L.
<br>
5. **OLL**: For OLL (Orientation of Last Layer), as we have already solved EO, we can use sune ```R' D' R D' R' D2 R <, D, D', D2>``` at most 4 times to solve OLL.
<br>
6. **PLL**: For PLL (Permutation of Last Layer):
    * use A-perm ```L2 B2 L F L' B2 L F' L <, D, D', D2>``` to solve the corners with depth of 2
    *  use U-perms ```R' D R' D' R' D' R' D R D R2 <, D, D', D2>``` to solve the rest of the edges with depth of 3
---