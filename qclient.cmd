laser connect=localhost:24919
mrc1 fwd 1
mrc1 turn 70
disp scale=3.0 pos=0.25
poollist
poolget img=97 savepng=foo.png
