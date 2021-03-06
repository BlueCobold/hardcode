out vec4 out_data;

//------------------------------------------------------------------------------------------
// IQ's noise fragment shader
//------------------------------------------------------------------------------------------
out vec4 out_aux;
void main()
{
	int n = int(gl_FragCoord.x * 40.0 + gl_FragCoord.y * 6400.0);
	n = (n << 13) ^ n;
	out_aux = out_data = vec4(1.0 - float( (n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}