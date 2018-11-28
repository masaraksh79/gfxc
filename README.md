# GFXC

Simple graphical plotting for schedulers in C

## Build example

gcc -Wall -o gfxc gfx-main.c gfx-noise.c

## Run-time example for TDMA cycle slot occupation

Running the command,

```> ./gfxc -s 105122 -i5 -c47```

generates this,

```
-----------------------------------------------------------
- Graph |*****************|********************|**|
- Slots |17               |20                  |2 |
-----------------------------------------------------------
- Occupied slots: 39 Free slots 8 Total slots 47

------------------------------------------------------------
- Graph |*****|**********|********|*******************|
- Slots |5    |10        |8       |19                 |
------------------------------------------------------------
- Occupied slots: 42 Free slots 5 Total slots 47

--------------------------------------------------------
- Graph |
- Slots |
--------------------------------------------------------
- Occupied slots: 0 Free slots 47 Total slots 47

----------------------------------------------------------
- Graph |**********|**|
- Slots |10        |2 |
----------------------------------------------------------
- Occupied slots: 12 Free slots 35 Total slots 47

-------------------------------------------------------------
- Graph |***|******|*********|*********|***********|
- Slots |3  |6     |9        |9        |11         |
-------------------------------------------------------------
- Occupied slots: 38 Free slots 9 Total slots 47
```
