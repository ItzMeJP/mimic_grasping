MODULE MainModule
  PERS tooldata photoneo:=[TRUE,[[-83.9293,104.623,159.994],[0.703963,-0.268575,0.100635,-0.649751]],[0.3,[0,0,160],[1,0,0,0],0,0,0]];
	CONST robtarget p1:=[[115.36,1324.97,543.37],[0.259423,-0.956125,-0.0586915,0.122802],[0,-1,0,1],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
	CONST robtarget p0:=[[115.50,1244.97,1224.88],[0.471132,-0.873001,-0.0527845,0.114531],[0,-1,0,1],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
	CONST robtarget p2:=[[193.16,1383.71,532.81],[0.267706,-0.816352,-0.49286,0.137812],[0,-2,0,1],[9E+09,9E+09,9E+09,9E+09,9E+09,9E+09]];
	PROC main()
		MoveL p0, v100, z50, photoneo;
		MoveL p1, v100, z50, photoneo;
		MoveL p2, v100, z50, photoneo;
	ENDPROC
ENDMODULE
