Last login: Mon Jul 10 21:21:40 on ttys000
Hojinui-MBP:~ hojinkim$ ssh -X hojinkim@capphub01.kaist.ac.kr
hojinkim@capphub01.kaist.ac.kr's password: 
Last login: Mon Jul 10 21:59:18 2017 from 143.248.215.185
--------------------------------------------------------------------------------
    
         CCCCCCCCCCC            AAA          PPPPPPPPPP       PPPPPPPPPP
        CCCCCCCCCCCCC          AAAAA         PPPPPPPPPPP      PPPPPPPPPPP
       CCC         CCC        AAA AAA        PPP      PPP     PPP       PPP
       CCC         CCC       AAA   AAA       PPP      PPP     PPP       PPP
       CCC                  AAA     AAA      PPP      PPP     PPP       PPP
       CCC                 AAAAAAAAAAAAA     PPPPPPPPPPP      PPPPPPPPPPPP
       CCC         CCC     AAAAAAAAAAAAA     PPPPPPPPPP       PPPPPPPPPPP
       CCC         CCC     AAA       AAA     PPP              PPP
        CCCCCCCCCCCCC      AAA       AAA     PPP              PPP
         CCCCCCCCCCC       AAA       AAA     PPP              PPP

       PPPP     RRRR      OOO     PPPP     EEEEE    RRRR     TTTTT    Y   Y
       P   P    R   R    O   O    P   P    E        R   R      T       Y Y
       PPPP     RRRR     O   O    PPPP     EEEEE    RRRR       T        Y
       P        R  R     O   O    P        E        R  R       T        Y
       P        R   R     OOO     P        EEEEE    R   R      T        Y

--------------------------------------------------------------------------------
NOTICE TO USERS

   This node is a property of Center for Axion and Precision Physics Research 
   (CAPP), Institute for Basic Science (IBS). Authorized use only. Users have 
   no explicit or implicit expectation of privacy.

   Any or all of uses of this system and all files on this system may be inte-
   rcepted, monitored, recorded, copied, audited, inspected, and disclosed to 
   authorized site and law enforcement personnel as well as authorized offici-
   als of other agencies, both domestic and foreign. By using this system, the
   user consents to such interception, monitoring, recording, copying, auditi-
   ng, inspection, and disclosure at the discretion of authorized site.

   Unauthorized or improper use of this system may result in administrative
   diciplinary action and civil and criminal penalties. By continuing to use
   this system you indicate your awareness of and consent to these terms and 
   conditions of use.

   LOG OFF IMMEDIATELY if you do not agree to the conditions stated in this 
   warning.

   If you need a help, please contact the system administrator:
      Soohyung Lee (CAPP/IBS), soohyunglee@ibs.re.kr
--------------------------------------------------------------------------------
-bash: warning: setlocale: LC_CTYPE: cannot change locale (UTF-8): No such file or directory
manpath: can't set the locale; make sure $LC_* and $LANG are correct
[hojinkim@capphub01 ~]$ ls
g-2
[hojinkim@capphub01 ~]$ cd g-2
[hojinkim@capphub01 g-2]$ ls
#example.py#  example.py  g-2  graph.py  graph.py~
[hojinkim@capphub01 g-2]$ mkdir hojinkim
[hojinkim@capphub01 g-2]$ ls
#example.py#  example.py  g-2  graph.py  graph.py~  hojinkim
[hojinkim@capphub01 g-2]$ rmv \#example.py#
-bash: rmv: command not found
[hojinkim@capphub01 g-2]$ rm \#example.py#
[hojinkim@capphub01 g-2]$ rm example.py; ls
g-2  graph.py  graph.py~  hojinkim
[hojinkim@capphub01 g-2]$ rm graph.py; ls
g-2  graph.py~  hojinkim
[hojinkim@capphub01 g-2]$ rm graph.py~; ls
g-2  hojinkim
[hojinkim@capphub01 g-2]$ :w
-bash: :w: command not found
[hojinkim@capphub01 g-2]$ cd hojinkim
[hojinkim@capphub01 hojinkim]$ ls
[hojinkim@capphub01 hojinkim]$ :wq
-bash: :wq: command not found
[hojinkim@capphub01 hojinkim]$ root
*** DISPLAY not set, setting it to 143.248.185.129:0.0
^X^C
[hojinkim@capphub01 hojinkim]$ chmod 755
chmod: missing operand after '755'
Try 'chmod --help' for more information.
[hojinkim@capphub01 hojinkim]$ chmod 755 example.py
chmod: cannot access 'example.py': No such file or directory
[hojinkim@capphub01 hojinkim]$ ls
[hojinkim@capphub01 hojinkim]$ cd
[hojinkim@capphub01 ~]$ cd ..
[hojinkim@capphub01 users]$ ls
alaa           doyu      jskang   mjlee                        stpark
bomki          eleni     jskim    onkim                        swyoun
cappvault      hojinkim  junu     root_v6.09.02.source.tar.gz  yoo
cappvault_old  hyjeong   lmiceli  sara                         zhanibek
dokim          jordan    miran    shlee
[hojinkim@capphub01 users]$ cd hojinkim
[hojinkim@capphub01 ~]$ ls
g-2
[hojinkim@capphub01 ~]$ cd g-2
[hojinkim@capphub01 g-2]$ cd
[hojinkim@capphub01 ~]$ ls
g-2
[hojinkim@capphub01 ~]$ cd g-2;ls
g-2  hojinkim
[hojinkim@capphub01 g-2]$ cd g-2;ls
#RooJordan2.cxx#  RooJordan2_cxx.d                     example.py~
RooJordan2.cxx    RooJordan2_cxx.so                    graph.C
RooJordan2.cxx~   RooJordan2_cxx_ACLiC_dict_rdict.pcm  graph.C~
RooJordan2.h      example.py
[hojinkim@capphub01 g-2]$ chmod 755 example.py
[hojinkim@capphub01 g-2]$ ./ example.py
-bash: ./: Is a directory
[hojinkim@capphub01 g-2]$ ./example.py
./example.py: line 4: from: command not found
./example.py: line 6: syntax error near unexpected token `"RooJordan2_cxx.so"'
./example.py: line 6: `gSystem.Load("RooJordan2_cxx.so")'
[hojinkim@capphub01 g-2]$ cd example.py
-bash: cd: example.py: Not a directory
[hojinkim@capphub01 g-2]$ emacs -nw example.py

File Edit Options Buffers Tools Python Help                                     

#!/usr/bin/python                                                               

from ROOT import *

gSystem.Load("RooJordan2_cxx.so")

t = RooRealVar("t", "time", 0., 30.e-6)
wa = RooRealVar("wa", "wa", 2.975e+6)
A = RooRealVar("A", "A",0.1)
phi = RooRealVar("phi", "phi", 0.01)
N = RooRealVar("N", "N", 10.e+8)
tau = RooRealVar("tau", "tau", 2.2e-6)

fwa = RooRealVar("fwa", "fwa", 1.1, 0., 10.0)
fA = RooRealVar("fA","fA",1.1, 0., 10.0)
fphi = RooRealVar("fphi","fphi",0.5,0.,10.0)
fN = RooRealVar("fN","fphi",1.1,0.,10.0)
ftau = RooRealVar("ftau","ftau",1.1,0.,10.0)

pdf = RooJordan2("pdf","pdf",t, wa, A, tau, phi, N)
-UU-:----F1  example.py     Top L1     (Python) --------------------------------
Can't guess python-indent-offset, using defaults: 4
