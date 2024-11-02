int toInteger(char ch){
    int num=0;
    switch(ch){
        case '1': num=1; break;
        case '2': num=2; break;
        case '3': num=3; break;
        case '4': num=4; break;
        case '5': num=5; break;
        case '6': num=6; break;
        case '7': num=7; break;
        case '8': num=8; break;
        case '9': num=9; break;
    }
    return num;
}
int getRoot(int num){
    int root=0;
    float getRoot=0.00;
    int othrRoot=0;
    if(num<0){
        num*=-1;
    }
    for(int i=0; i<10000; i++){
        if(getRoot>=1){
            getRoot=0;
            root+=1;
        }
        othrRoot=(root+getRoot)*(root+getRoot);
        if(othrRoot==num){
            if(getRoot>=0.5){
                root+=1;
            }
            break;
        }
        getRoot+=0.01;
        //printf("%i \n",othrRoot);
    }
    return root;
}
int pow(int num, int num2){
    int power=1;
    for(int i=0; i<num2; i++){
        power*=num;
    }
    return power;
}
int alltoint(char equ[], int len, int st){
    int nn=0;
    int s=0;
    int ii=0;
    char ch[len];
    for(int i=st; i<len; i++){
        if(equ[i]=='0'||equ[i]=='1'||equ[i]=='2'||equ[i]=='3'||equ[i]=='4'||equ[i]=='5'||equ[i]=='6'||equ[i]=='7'||equ[i]=='8'||equ[i]=='9'){
            ch[s]=equ[i];
            s+=1;
            //printf("\n%c",equ[i]);
        } else {
            break;
        }
    }
    ii=s;
    for(int i=0; i<len; i++){
        if(toInteger(ch[i])!=0){
            ii-=1;
            nn+=(toInteger(ch[i])*pow(10,ii));
        }
    }
    return nn;
}
int SQRTequation(char equ[], int len){
    int a=0;
    int b=0;
    int c=0; 
    int Ds=0; //дескриминант
    int new=0; //переходить ли на след число
    int state=1; //Номер цифры в строке
    int x1, x2=0;
    //int len=sizeof(equ)/sizeof(char);
    for(int i=0; i<len; i++){
        if(i+1<len){
            if(equ[i]=='0'||equ[i]=='1'||equ[i]=='2'||equ[i]=='3'||equ[i]=='4'||equ[i]=='5'||equ[i]=='6'||equ[i]=='7'||equ[i]=='8'||equ[i]=='9'){
                if(new!=1){
                    int nn=alltoint(equ,len,i);
                    //printf("\n %i",alltoint(equ,len,i));
                    if(equ[i-1]=='-'&&i-1>=0){
                        if(a==0){
                            a=nn;
                            a*=-1;
                        }else if(b==0){
                            b=nn;
                            b*=-1;
                        }else if(c==0){
                            c=nn;
                            c*=-1;
                        }
                    } else {
                        if(a==0){
                            a=nn;
                        }else if(b==0){
                            b=nn;
                        }else if(c==0){
                            c=nn;
                        }
                    }
                    new=1;
                }
            } else {
                new=0;
            }
        }
    }
    Ds=(b*b)-(4*a*c);
    x1=(-b+getRoot(Ds))/(2*a);
    x2=(-b-getRoot(Ds))/(2*a);
    printf("\n%i, %i, %i, %i, %i, %i \n", a, b, c, Ds, x1, x2);
    return 0;
}