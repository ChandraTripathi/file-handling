#include<stdio.h>
#include<conio.h>

int main()
{
    FILE *fp , *target;
    char ch, fname[30], newch[500],target_file[30];
    int i=0, j, COUNT=0;
    printf("Enter the filename with extension: ");
    gets(fname);
    fp = fopen(fname, "r");
    if(!fp)
    {
        printf("Error in opening the file...\nExiting...");
        getch();
        return 0;
    }
   
    printf("\nThe original content is:\n\n");
    ch = getc(fp);
    while(ch != EOF)
    {
        COUNT++;
        putchar(ch);
        newch[i] = ch;
        i++;
        ch = getc(fp);
    }
    printf("\n\n\n");
    printf("The content in reverse order is:\n\n");
    for(j=(COUNT-1); j>=0; j--)
    {
        ch = newch[j];
        printf("%c", ch);
    }
        printf("\nEnter name of target file\n");
   gets(target_file);
 
   target = fopen(target_file, "w");
   if( target == NULL )
   {
      fclose(fp);
      printf("Error in opening the file...\nExiting...");
        getch();
        return 0;
   }
   while( ( ch = fgetc(fp) ) != EOF )
      fputc(ch, target);
 
   printf("File copied successfully.\n");
   fclose(target);
   fclose(fp);
    printf("\n");
    getch();
    return 0;
}

 

