
BLOW_DEFINE_EFFECT1(logo,`
	int x=(int)Math.round((Math.random()*(width-24)));
	int y=(int)Math.round((Math.random()*(height-20)));

	for(int v=0;v<20;v++){
	    for(int u=0;u<24;u++){
		buf[(v+y)*width+u+x]=logo[v*24+u];
	    }
	}
')
BLOW_DEFINE_GLOBAL(`int[]',`logo')
BLOW_ADD_INITIALIZER(`initLogo();')


private void initLogo(){
/* Made with GIMP */
int hype_bits[] = {
   0xf0, 0x3c, 0x00, 0xbf, 0xfc, 0x00, 0x83, 0xfd, 0x03, 0x06, 0x7f, 0x1e,
   0x0c, 0x86, 0x3d, 0x1c, 0x98, 0xe3, 0x38, 0xf0, 0xc7, 0x70, 0xd8, 0x4f,
   0xe0, 0x8e, 0x3f, 0xe0, 0x03, 0x1e, 0xc0, 0x03, 0x3c, 0x80, 0x07, 0x7e,
   0x00, 0x0f, 0xdf, 0x00, 0x9e, 0xdf, 0x00, 0xfe, 0xfe, 0x00, 0x7f, 0x78,
   0x80, 0x39, 0x00, 0x80, 0x08, 0x00, 0x80, 0x0f, 0x00, 0x00, 0x06, 0x00 };
logo=new int[24*20];
int a=0;
for(int i=0;i<24*20;i++){
if((i&0x7)==0){
	a=hype_bits[i/8];
}
logo[i]=(a&(0x1<<(i&0x7)))==0?0:0xFFFFFF;
}
}