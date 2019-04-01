#include<stdio.h>
#include<string.h>
//int main()
//{
//	char const *p = "C:\\Users\\rmk\\Desktop\\1.txt";
//	FILE *fw = fopen(p,"w");
//	char *str = "55555";
//	fwrite(str, sizeof(char),strlen(str),fw);
//	/*char buffer[100] = {};
//	fread(buffer, sizeof(char), 100, fr);
//	printf("%s\n", buffer);*/
//	return 0;
void copymp4(const char *dest, const char *src)
{
	FILE *fr = fopen(src, "rb");
	FILE *fw = fopen(src, "wb");
	char ch;
	int len = 0;
	while ((len = fread(&ch, sizeof(char), 1, fr))>0)
		fwrite(&ch, sizeof(char), len, fw);
	fclose(fr);
	fclose(fw);
}
int main()
{
	char *srcpath = "e:\\¡¡Ω£.mp4";
	char *destpath = "d:\\¿œ¿Ó.mp4";
	copymp4(srcpath, destpath);
}
