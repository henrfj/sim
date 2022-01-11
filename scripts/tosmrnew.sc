if [ $# -ne 2 ] ; then
echo "parameters are study number and group number"
else
scp -J $1@login.gbar.dtu.dk * k385h$2@tustin.iau.dtu.dk:live
fi
