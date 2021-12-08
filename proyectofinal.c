#include<stdio.h>
#include<math.h>
/*defines*/
    #define is_a_number (num > 47 && num < 58)
    #define isnt_a_char (i > 47 && i < 58)
    #define All_to_zero count=0
/*Variables*/
    int units,prices,costetotal;
    int count,countbuy,howmany_products;
    char function,ch,ch1,ch2,ch3;
    FILE* stock;
    FILE* concatenado;
    FILE* concatenar2;
    int P[100],U[100],S[100],U1[15];
    int i,i1;
    char expression;
    int P1,P2,P3,P4,P5,P6,P7,P8,P9,P10,P11,P12,P13,P14,P15,P16;
/*program functions*/
int check_if_a_number(char num)
{
    if (is_a_number)
        concatenar(num);
}
void concatenar1()
{
    i -= '0'; 
    prices = ((prices * 10) + i);
}
void concatenar()
{
    i -= '0'; 
    units = ((units * 10) + i);
}
void print_bill()
{   
    system("cls");
    printf("                            HEll Super Market                            \n\n");
    printf("                                 BILL\n");
    printf("Product        Cantidad        Cost     ");
    countbuy+=2;
    for ( i = 1; i < countbuy; i++)
    {
        printf("\n%d                 %d          $%d              \n",P[i],U1[i],S[i]);
    }
    for ( i = 1; i < howmany_products; i++)
    {
       costetotal+=(U1[i]*S[i]);
    }
    printf("\nCoste total-------------------------------->%i",costetotal);

    All_to_zero;
}
void save_changes_to_stock()
{

}
void evaluate_stock()
{
    stock=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","r");
    while ((i=fgetc(stock)) != EOF)
    {   
        if(i=='P')
        {
            howmany_products++;
            i=fgetc(stock);
            i-='0';
            P[howmany_products]=i;
        }
    }
    fclose(stock);
    stock=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","r");
    All_to_zero;
    while ( count != howmany_products)
    {   
        i=fgetc(stock);
        if(i=='U')
        {
            count++;
            i=fgetc(stock);
            while(isnt_a_char)
            {
                 concatenar();
                i=fgetc(stock);
            }
            U[count]=units;
            units=0;
        }   
    }
    fclose(stock);
    stock=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","r");
    All_to_zero;
    while ( count != howmany_products)
    {   
        i=fgetc(stock);
        if(i=='S')
        {
            count++;
            i=fgetc(stock);
            while(isnt_a_char)
            {
                concatenar1();
                i=fgetc(stock);
            }
            S[count]=prices;
            prices=0;
        }   
    }
    All_to_zero;

    fclose(stock);
}

void Selling()
{   
    
    system("cls");
    printf("        You are on the selling interface\n");

    printf("Register the products and when finish just press Enter key\n");
    
    while (expression !='\n')
    {    
        countbuy++;
        getchar();
        expression=getchar();
        switch (expression)
        {
        case '1' :
        expression-='0';
        U1[expression]+=1;
        break;
        case '2':
        expression-='0';
        U1[expression]++;
        
         break;
        case '3':
        expression-='0';
         U1[expression]++;
         break;
         case '4':
         expression-='0';
         U1[expression]++;
         break;
         case '5':
         expression-='0';
         U1[expression]++;
         break;
         case 6:
         P6++;
         break;
         case 7:
         P7++;
         break;
         case 8:
         P8++;
         break;
         case 9:
         P9++;
         break;
         case 15:
         P10++;
         break;
         case 11:
         P11++;
         break;
         case 12:
         P12++;
         break;
         case 13:
         P13++;
         break;
         case 14:
         P14++;
         break;
         case 10:
         break;
        default:
            printf("Product not existing, check the code again\n");
            expression=0;
            count--;
            break;
           
        }
    }
    evaluate_stock();
    print_bill();
    save_changes_to_stock();

}
void reset_stocklist()
{
    concatenar2=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","w");
    fclose(concatenar2);
    printf("Reseting stock list....\n");
    sleep(5);
    printf("stock list reseted succesfully...");
    sleep(3);
    system("cls");
}
void updatealmacen()
{
    concatenar2=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","w");
    concatenado=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/concatenado.txt","r");
    
    while ((ch2=fgetc(concatenado)) != EOF)
    {
        fputc(ch2,concatenar2);
    }
    fclose(concatenar2);
    fclose(concatenado);
    ch2=0;

}
void concatenar_stock()
{
    stock=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/stock.txt","r");
    concatenar2=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","r");
    concatenado=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/concatenado.txt","w");

    while ((ch2=fgetc(stock)) != EOF)
    {
        fputc(ch2,concatenado);
    }
    
    while ((ch3=fgetc(concatenar2)) != EOF)
    {
        fputc(ch3,concatenado);
    }
    
    fclose(stock);
    fclose(concatenar2);
    fclose(concatenado);
    ch2=ch3=0;
    updatealmacen();

}

void add_stock()
{   
    system("cls");
    fflush(stdin);
    stock=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/stock.txt","w");
    printf("Product         On stock         SPrice\n");
    
    while ( ch1 != '\n')
    {
        ch1=getchar();
       fputc(ch1,stock);
    }
    
    

    fclose(stock);
    ch1=0;

    concatenar_stock();
    system("cls");
}
void homeprint()
{

    printf("                            HEll Super Market                            \n\n");
    printf("                                 HOME MENU\n");
    printf("                   Welcome to Hell Super Market interface \n");
    printf("                      what do you want to do?\n\n 1)Stock Details\n 2)ADD an item to the stock\n 3)reset stock\n 4)Selling interface\n    ");
}
void seestock()
{
    system("cls");
    printf("                            What The HEll Super Market ---->STOCK                           \n\n");
    printf("Product      stock by U     Price\n");
    stock=fopen("C:/Users/wande.DESKTOP-JVNGD0L/Downloads/C programing/.vscode/Nueva carpeta/almacen.txt","r"); 
   
    while ((ch=fgetc(stock)) != EOF)
    {
        printf("%c",ch);
    }
    
    fclose(stock);
    ch=0;
    getche();
    system("cls");
}



int main()
{   
    fflush(stdin);
    homeprint();
    scanf("%c",&function);
    switch (function)
    {
        case '1':
        seestock();
        break;

        case '2':
        add_stock();
        break;
        case '3':
        reset_stocklist();
        break;
        case '4':
        Selling();
        break;
     default:
        break;
    }

    main();
    return 0;
}
