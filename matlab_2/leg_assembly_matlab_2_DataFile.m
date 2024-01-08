% Simscape(TM) Multibody(TM) version: 23.2

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(35).translation = [0.0 0.0 0.0];
smiData.RigidTransform(35).angle = 0.0;
smiData.RigidTransform(35).axis = [0.0 0.0 0.0];
smiData.RigidTransform(35).ID = "";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [8.7542277142946343 18.477202645475387 7.5304606526493156];  % mm
smiData.RigidTransform(1).angle = 0;  % rad
smiData.RigidTransform(1).axis = [0 0 0];
smiData.RigidTransform(1).ID = "B[gripper_link-1:-:tibia_link-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [8.7542277142896019 18.477202645477679 7.5304606526493201];  % mm
smiData.RigidTransform(2).angle = 1.2225062931717347e-15;  % rad
smiData.RigidTransform(2).axis = [-0.89696994440740929 -0.44209152766114984 2.4238804219566465e-16];
smiData.RigidTransform(2).ID = "F[gripper_link-1:-:tibia_link-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [20.391101056458993 37.000000000000014 -20.500000000000004];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(3).ID = "B[base_link-1:-:shoulder_link-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [20.39110105644243 37.00000000000081 -20.500000000000199];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(4).axis = [0.57735026918962584 -0.57735026918962573 0.57735026918962573];
smiData.RigidTransform(4).ID = "F[base_link-1:-:shoulder_link-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [10.002588024609695 18.700000000000802 0.88583604003649885];  % mm
smiData.RigidTransform(5).angle = 0.013141931207965449;  % rad
smiData.RigidTransform(5).axis = [-5.9139865745952331e-14 -1 3.8861161676112775e-16];
smiData.RigidTransform(5).ID = "B[shoulder_link-1:-:tibia_link-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-39.444239704045984 114.71737175999084 34.330460652649293];  % mm
smiData.RigidTransform(6).angle = 2.3371195119139117;  % rad
smiData.RigidTransform(6).axis = [0.42543208552727696 0.63992481613229846 0.63992481613229824];
smiData.RigidTransform(6).ID = "F[shoulder_link-1:-:tibia_link-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [8.7542277142895397 18.477202645477725 42.330460652649307];  % mm
smiData.RigidTransform(7).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(7).axis = [0.98032834826793602 0.19737357873398462 -2.6157366834953999e-17];
smiData.RigidTransform(7).ID = "AssemblyGround[tibia_link-1:mini servo mount-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [-34.833802999868787 116.65228090431137 34.330460652647972];  % mm
smiData.RigidTransform(8).angle = 1.8823197464481529;  % rad
smiData.RigidTransform(8).axis = [0.72855806604537232 -0.48435686451222376 -0.48435686451222543];
smiData.RigidTransform(8).ID = "AssemblyGround[tibia_link-1:mg996r horn disk-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [0 0 20.344871140817002];  % mm
smiData.RigidTransform(9).angle = 0;  % rad
smiData.RigidTransform(9).axis = [0 0 0];
smiData.RigidTransform(9).ID = "AssemblyGround[tibia_link-1:Assembly SERVO-1:Assembly SERVO.stp-1:Assembly servo inside.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(10).translation = [0 0 20.344871140817002];  % mm
smiData.RigidTransform(10).angle = 0;  % rad
smiData.RigidTransform(10).axis = [0 0 0];
smiData.RigidTransform(10).ID = "AssemblyGround[tibia_link-1:Assembly SERVO-1:Assembly SERVO.stp-1:Assembly servo outside.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(11).translation = [0 0 0];  % mm
smiData.RigidTransform(11).angle = 0;  % rad
smiData.RigidTransform(11).axis = [0 0 0];
smiData.RigidTransform(11).ID = "AssemblyGround[tibia_link-1:Assembly SERVO-1:Assembly SERVO.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(12).translation = [6.6742003841453563 23.43342210246842 4.1855895118323163];  % mm
smiData.RigidTransform(12).angle = 1.9681524679374278;  % rad
smiData.RigidTransform(12).axis = [-2.9232701723489235e-16 8.8932405083565207e-16 1];
smiData.RigidTransform(12).ID = "AssemblyGround[tibia_link-1:Assembly SERVO-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(13).translation = [9.0509240422284591 18.665659712120085 22.115954427231252];  % mm
smiData.RigidTransform(13).angle = 0;  % rad
smiData.RigidTransform(13).axis = [0 0 0];
smiData.RigidTransform(13).ID = "AssemblyGround[gripper_link-1:Assem1-1:Suction cup-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(14).translation = [9.0507675600917104 18.704122492608388 31.542214856707552];  % mm
smiData.RigidTransform(14).angle = 1.5707963267948968;  % rad
smiData.RigidTransform(14).axis = [-1 -0 -0];
smiData.RigidTransform(14).ID = "AssemblyGround[gripper_link-1:Assem1-1:Spring-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(15).translation = [9.0509240422284662 18.665659712120085 48.918016620327798];  % mm
smiData.RigidTransform(15).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(15).axis = [0.80371962167047539 -0.59500820981047631 0];
smiData.RigidTransform(15).ID = "AssemblyGround[gripper_link-1:Assem1-1:Spring holder-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(16).translation = [-36.739648328804556 39.618949993395752 31.54221485670756];  % mm
smiData.RigidTransform(16).angle = 1.8388172996596639;  % rad
smiData.RigidTransform(16).axis = [-0.76239634323304006 -0.4575761225331193 0.4575761225331193];
smiData.RigidTransform(16).ID = "AssemblyGround[gripper_link-1:Assem1-1:Spring-6]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(17).translation = [-31.656299159111086 -10.367458949785885 22.115954427231259];  % mm
smiData.RigidTransform(17).angle = 2.2608953104065628;  % rad
smiData.RigidTransform(17).axis = [0 0 1];
smiData.RigidTransform(17).ID = "AssemblyGround[gripper_link-1:Assem1-1:Suction cup-5]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(18).translation = [-31.876741085003033 -10.617945456925654 31.54221485670756];  % mm
smiData.RigidTransform(18).angle = 3.12868957942946;  % rad
smiData.RigidTransform(18).axis = [-0.0064516265909934012 -0.7070920649089234 0.7070920649089234];
smiData.RigidTransform(18).ID = "AssemblyGround[gripper_link-1:Assem1-1:Spring-7]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(19).translation = [0 0 20.344871140817006];  % mm
smiData.RigidTransform(19).angle = 0;  % rad
smiData.RigidTransform(19).axis = [0 0 0];
smiData.RigidTransform(19).ID = "AssemblyGround[gripper_link-1:Assem1-1:Assembly SERVO.stp-1:Assembly servo inside.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(20).translation = [0 0 20.344871140817006];  % mm
smiData.RigidTransform(20).angle = 0;  % rad
smiData.RigidTransform(20).axis = [0 0 0];
smiData.RigidTransform(20).ID = "AssemblyGround[gripper_link-1:Assem1-1:Assembly SERVO.stp-1:Assembly servo outside.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(21).translation = [-4.4423642932046246 49.340183595709988 79.012887761144782];  % mm
smiData.RigidTransform(21).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(21).axis = [-0.54095350928771468 0.8410524958581993 -3.8959952939061348e-17];
smiData.RigidTransform(21).ID = "AssemblyGround[gripper_link-1:Assem1-1:Assembly SERVO.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(22).translation = [-36.446105870740098 39.402589791050644 22.115954427231273];  % mm
smiData.RigidTransform(22).angle = 2.6063677705391566;  % rad
smiData.RigidTransform(22).axis = [-0 -0 -1];
smiData.RigidTransform(22).ID = "AssemblyGround[gripper_link-1:Assem1-1:Suction cup-6]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(23).translation = [-2.2131443097195764 54.231114311354105 75.668016620327762];  % mm
smiData.RigidTransform(23).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(23).axis = [-0.7412688304550944 0.67120825456465938 3.928777050156301e-16];
smiData.RigidTransform(23).ID = "AssemblyGround[gripper_link-1:Assem1-1:Microservo horn-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(24).translation = [-9.3514455142806252 -80.333598524877559 -38.38755596767848];  % mm
smiData.RigidTransform(24).angle = 0;  % rad
smiData.RigidTransform(24).axis = [0 0 0];
smiData.RigidTransform(24).ID = "AssemblyGround[gripper_link-1:Assem1-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(25).translation = [8.7542277142946343 18.477202645475387 7.5304606526493156];  % mm
smiData.RigidTransform(25).angle = 1.1428144086499563;  % rad
smiData.RigidTransform(25).axis = [0 0 1];
smiData.RigidTransform(25).ID = "AssemblyGround[gripper_link-1:Microservo horn-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(26).translation = [0 0 0];  % mm
smiData.RigidTransform(26).angle = 0;  % rad
smiData.RigidTransform(26).axis = [0 0 0];
smiData.RigidTransform(26).ID = "AssemblyGround[shoulder_link-1:MG996R.STEP-1:servo.STEP-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(27).translation = [-10.108898943540986 42.999999999999979 0];  % mm
smiData.RigidTransform(27).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(27).axis = [-0.28533392338519631 0 0.95842816745211057];
smiData.RigidTransform(27).ID = "AssemblyGround[shoulder_link-1:MG996R.STEP-1:shaft.STEP-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(28).translation = [20.623134588826183 18.700000000000806 -37.977949526066453];  % mm
smiData.RigidTransform(28).angle = 1.5708395037624474;  % rad
smiData.RigidTransform(28).axis = [0.99995682396454744 -0.0065707764661061064 0.0065707764661063562];
smiData.RigidTransform(28).ID = "AssemblyGround[shoulder_link-1:MG996R.STEP-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(29).translation = [20.391449010847218 32.20000000000082 -20.349471945941829];  % mm
smiData.RigidTransform(29).angle = 1.5708395037624476;  % rad
smiData.RigidTransform(29).axis = [0.99995682396454744 -0.0065707764661060205 0.0065707764661062703];
smiData.RigidTransform(29).ID = "AssemblyGround[shoulder_link-1:MG996 servo mount-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(30).translation = [20.391101056442416 30.700000000000809 -20.500000000000174];  % mm
smiData.RigidTransform(30).angle = 3.1306031415945492;  % rad
smiData.RigidTransform(30).axis = [-0.0054948112981434765 0.70709610628570085 0.70709610628570063];
smiData.RigidTransform(30).ID = "AssemblyGround[shoulder_link-1:Servo MG996R arm01-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(31).translation = [31.499999999999972 53.000000000000021 -20.500000000000004];  % mm
smiData.RigidTransform(31).angle = 1.5707963267948968;  % rad
smiData.RigidTransform(31).axis = [1 1.2143064331837647e-16 -1.2143064331837647e-16];
smiData.RigidTransform(31).ID = "AssemblyGround[base_link-1:MG996 servo mount 2 with hing (Upper body)-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(32).translation = [0 0 0];  % mm
smiData.RigidTransform(32).angle = 0;  % rad
smiData.RigidTransform(32).axis = [0 0 0];
smiData.RigidTransform(32).ID = "AssemblyGround[base_link-1:MG996R.STEP-3:servo.STEP-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(33).translation = [-10.108898943540998 43 0];  % mm
smiData.RigidTransform(33).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(33).axis = [-0.2853339233851962 0 0.95842816745211068];
smiData.RigidTransform(33).ID = "AssemblyGround[base_link-1:MG996R.STEP-3:shaft.STEP-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(34).translation = [30.499999999999993 76.000000000000014 -20.500000000000004];  % mm
smiData.RigidTransform(34).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(34).axis = [1 0 -6.0715321659188248e-17];
smiData.RigidTransform(34).ID = "AssemblyGround[base_link-1:MG996R.STEP-3]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(35).translation = [-9.3554648171659878 24.683076023354957 95.509253788316656];  % mm
smiData.RigidTransform(35).angle = 0;  % rad
smiData.RigidTransform(35).axis = [0 0 0];
smiData.RigidTransform(35).ID = "RootGround[base_link-1]";


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(13).mass = 0.0;
smiData.Solid(13).CoM = [0.0 0.0 0.0];
smiData.Solid(13).MoI = [0.0 0.0 0.0];
smiData.Solid(13).PoI = [0.0 0.0 0.0];
smiData.Solid(13).color = [0.0 0.0 0.0];
smiData.Solid(13).opacity = 0.0;
smiData.Solid(13).ID = "";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.037716238951945848;  % kg
smiData.Solid(1).CoM = [0.46806516614435301 -61.431448349064631 8.8643364227929897];  % mm
smiData.Solid(1).MoI = [54.689037278801003 2.8698372668246561 53.347555321230729];  % kg*mm^2
smiData.Solid(1).PoI = [0.27706062814347665 -0.058882227161222107 0.63736034782857387];  % kg*mm^2
smiData.Solid(1).color = [1 1 1];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = "mini servo mount*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 0.00063336481035485199;  % kg
smiData.Solid(2).CoM = [0 0 1.32085305574777];  % mm
smiData.Solid(2).MoI = [0.015547660291995297 0.015547660291995251 0.029811377124477255];  % kg*mm^2
smiData.Solid(2).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(2).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = "mg996r horn disk*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.0021514313917404956;  % kg
smiData.Solid(3).CoM = [0.95344001091226338 0.0024920530973286952 2.9640901626249088];  % mm
smiData.Solid(3).MoI = [0.1266767862371716 0.18985269872603194 0.091612046027185728];  % kg*mm^2
smiData.Solid(3).PoI = [6.4013395411860976e-06 -0.042964626926470462 -1.2698193491562629e-05];  % kg*mm^2
smiData.Solid(3).color = [0.95686274509803915 0.95686274509803915 0.95686274509803915];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = "Assembly servo inside.stp*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 0.0027322825687335697;  % kg
smiData.Solid(4).CoM = [-0.41833362463059337 -0.0014630346207467233 1.8322920963420744];  % mm
smiData.Solid(4).MoI = [0.2263094609039438 0.34876970521585232 0.22449034442471089];  % kg*mm^2
smiData.Solid(4).PoI = [6.8098767625706508e-07 -0.015498668750467378 -8.4053371869451859e-07];  % kg*mm^2
smiData.Solid(4).color = [0.0078431372549019607 0.0078431372549019607 0.0078431372549019607];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = "Assembly servo outside.stp*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(5).mass = 0.00096631801709073906;  % kg
smiData.Solid(5).CoM = [0.0006221492041204727 -0.00016018501093021119 4.1955177184265322];  % mm
smiData.Solid(5).MoI = [0.066139911556962375 0.066200510220360331 0.11486249507537785];  % kg*mm^2
smiData.Solid(5).PoI = [-5.0804802432572735e-07 1.760482084180789e-06 4.7472465625278618e-06];  % kg*mm^2
smiData.Solid(5).color = [1 1 1];
smiData.Solid(5).opacity = 1;
smiData.Solid(5).ID = "Suction cup*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(6).mass = 0.00085519259447285534;  % kg
smiData.Solid(6).CoM = [0.18613062208043851 -7.4750086152248274 0.01168243751487206];  % mm
smiData.Solid(6).MoI = [0.02050845479506451 0.013814380327993781 0.020455864362558206];  % kg*mm^2
smiData.Solid(6).PoI = [-0.00013926687283072041 7.8322257852691252e-06 9.2478075429712421e-06];  % kg*mm^2
smiData.Solid(6).color = [0.65098039215686276 0.61960784313725492 0.58823529411764708];
smiData.Solid(6).opacity = 1;
smiData.Solid(6).ID = "Spring*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(7).mass = 0.054573428321044004;  % kg
smiData.Solid(7).CoM = [-23.640979256919657 12.479079364093124 -3.4351168671415961];  % mm
smiData.Solid(7).MoI = [45.436794747545989 52.902887634408224 87.285266486109066];  % kg*mm^2
smiData.Solid(7).PoI = [-5.7109853711426561 -6.4538258179812447 -30.195957951896492];  % kg*mm^2
smiData.Solid(7).color = [1 1 1];
smiData.Solid(7).opacity = 1;
smiData.Solid(7).ID = "Spring holder*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(8).mass = 0.0024998463034132971;  % kg
smiData.Solid(8).CoM = [0 0 1.56861414053556];  % mm
smiData.Solid(8).MoI = [0.011370129697881284 0.15625956144783962 0.15995072178776629];  % kg*mm^2
smiData.Solid(8).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(8).color = [1 1 1];
smiData.Solid(8).opacity = 1;
smiData.Solid(8).ID = "Microservo horn*:*?? ?????????";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(9).mass = 0.030618086130328986;  % kg
smiData.Solid(9).CoM = [-0.1338008046128171 18.77941289959637 0];  % mm
smiData.Solid(9).MoI = [4.551912619365976 5.3252855816552644 7.8658675477353617];  % kg*mm^2
smiData.Solid(9).PoI = [0 0 0.075658020823037506];  % kg*mm^2
smiData.Solid(9).color = [0.098039215686274508 0.098039215686274508 0.098039215686274508];
smiData.Solid(9).opacity = 1;
smiData.Solid(9).ID = "servo.STEP*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(10).mass = 9.2739815133970692e-05;  % kg
smiData.Solid(10).CoM = [0 2 0];  % mm
smiData.Solid(10).MoI = [0.00035608224852480845 0.0004648583233590281 0.00035608224852480834];  % kg*mm^2
smiData.Solid(10).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(10).color = [0.6470588235294118 0.51764705882352935 0];
smiData.Solid(10).opacity = 1;
smiData.Solid(10).ID = "shaft.STEP*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(11).mass = 0.0087006546575156378;  % kg
smiData.Solid(11).CoM = [0 0.7218034448122983 14.469515138761324];  % mm
smiData.Solid(11).MoI = [1.0775602874972701 3.6734315437005947 3.0071047060530591];  % kg*mm^2
smiData.Solid(11).PoI = [0.0060887126214287596 -7.6296548484595083e-06 0];  % kg*mm^2
smiData.Solid(11).color = [1 1 1];
smiData.Solid(11).opacity = 1;
smiData.Solid(11).ID = "MG996 servo mount*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(12).mass = 0.00068370531177794748;  % kg
smiData.Solid(12).CoM = [0 0 1.6447525623491228];  % mm
smiData.Solid(12).MoI = [0.0055339348619207925 0.055618893878790002 0.059083463846795997];  % kg*mm^2
smiData.Solid(12).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(12).color = [0.75294117647058822 0.75294117647058822 0.75294117647058822];
smiData.Solid(12).opacity = 1;
smiData.Solid(12).ID = "Servo MG996R arm01*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(13).mass = 0.056764392265510936;  % kg
smiData.Solid(13).CoM = [32.510696054692467 8.4021853443598271 29.604230133473614];  % mm
smiData.Solid(13).MoI = [46.821805936237297 78.584465005805896 70.571088278016035];  % kg*mm^2
smiData.Solid(13).PoI = [-1.2368027434247821 0.51195391116281463 -15.881542859952715];  % kg*mm^2
smiData.Solid(13).color = [1 1 1];
smiData.Solid(13).opacity = 1;
smiData.Solid(13).ID = "MG996 servo mount 2 with hing (Upper body)*:*Default";


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(3).Rz.Pos = 0.0;
smiData.RevoluteJoint(3).ID = "";

smiData.RevoluteJoint(1).Rz.Pos = -47.269685911454687;  % deg
smiData.RevoluteJoint(1).ID = "[gripper_link-1:-:tibia_link-1]";

smiData.RevoluteJoint(2).Rz.Pos = 111.74702280713215;  % deg
smiData.RevoluteJoint(2).ID = "[base_link-1:-:shoulder_link-1]";

smiData.RevoluteJoint(3).Rz.Pos = 5.1087272828945432e-14;  % deg
smiData.RevoluteJoint(3).ID = "[shoulder_link-1:-:tibia_link-1]";

