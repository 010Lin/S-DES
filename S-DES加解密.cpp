#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static int IP[]={2,6,3,1,4,8,5,7}; //��ʼ�û� 
static int IP_1[]={4,1,3,5,7,2,8,6};  //�����û� 

//��Կ���� 
static int P10[]={3,5,2,7,4,10,1,9,8,6}; //��Կ��չ 
static int P8[]={6,3,7,4,8,5,10,9}; //��Կѹ�� 
//�ֺ���F  
static int P4[]={2,4,3,1};  //SPBpx ֱ���û� 
static int EP[]={4,1,2,3,2,3,4,1};  //EPBox ��չ�û� 
static int S0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,0,2}};
static int S1[4][4]={{0,1,2,3},{2,3,1,0},{3,0,1,2},{2,1,0,3}};

//�ϲ����麯�� 
void merge(char *num,char *x,char *y,int n){ 
	n/=2;
	for(int i=0;i<n;i++){
		num[i]=x[i];
		num[i+n]=y[i];  //����Ϊn/2������x��y�ϲ���Ϊ����num 
	}
}

//�û����� 
void change(char *z1,char *z2,int *P,int n){ //nΪ�����鳤�� 
		for(int i=0;i<n;i++)
			z2[i]=z1[(P[i]-1)];  //��z1����ĵ�(P[i]-1) ��������z2����ĵ�i�� 
}

//������������ת�ַ��ͺ��� 
char intz(int n){
	if(n==1)
	return '1';
	else 
	return '0';
}

//����Կ���� 
void key(char *mkey,char *k1,char *k2)
{
	char temp1[5];char temp2[5];//S1-L,S2-L �����/�Ұ벿�� 
	char mkey1[10];//��ʱ����
	change(mkey,mkey1,P10,10);//��ʼ��Կ����P10�û� 
	for(int j=0;j<5;j++)//���Ҳ��
	{
		temp1[j]=mkey1[j];
		temp2[j]=mkey1[j+5];
	}
	char x=temp1[0];char y=temp2[0];//����һλ
	for(int k=0;k<4;k++)
	{
		temp1[k]=temp1[k+1];
		temp2[k]=temp2[k+1];
	}
	temp1[4]=x;temp2[4]=y; //�ͷ��һλ����� 
	merge(mkey1,temp1,temp2,10);//�ϲ�
	change(mkey1,k1,P8,8);//P8�û� ������Կk1 
//	cout<<"����Կk1Ϊ��"<<endl;
//	for(int i=0;i<8;i++)
//	cout<<k1[i];
//	cout<<endl; 
	/*
	char a=temp1[0],b=temp1[1];
	char c=temp2[0],d=temp2[1];
	for(int f=0;f<3;f++)//������λ
	{ 
		temp1[f]=temp1[f+2];
		temp2[f]=temp2[f+2];
	}
	temp1[3]=a,temp1[4]=b;
	temp2[3]=c,temp2[4]=d;
	*/
	x=temp1[0];y=temp2[0];//����һλ
	for(int k=0;k<4;k++)
	{
		temp1[k]=temp1[k+1];
		temp2[k]=temp2[k+1];
	}
	temp1[4]=x;temp2[4]=y; //�ͷ��һλ����� 

    merge(mkey1,temp1,temp2,10);//�ϲ� 
    change(mkey1,k2,P8,8);//P8�û� ������Կk2 
  //  cout<<"����Կk2Ϊ��"<<endl;
  //  for(int i=0;i<8;i++)
  //	cout<<k2[i];
//	cout<<endl; 
}

//���������� 
void DES(char *temp,char *k1,char *Rm,char *Lm1){ //tempΪ���� 
	char Lm[4];  //��벿�� 
	int i=0;
	char Rm1[8];  //�Ұ벿��Rm����EP��չ���Rm1 
	for(i=0;i<4;i++){//���
		Lm[i]=temp[i];
		Rm[i]=temp[i+4];
	} 
	 
	for(i=0;i<8;i++){//EP��չ�û���Rm1������ԿK1��λ��� ���ΪRm1 
		Rm1[i]=Rm[(EP[i]-1)];
		
		if(Rm1[i]==k1[i])
		Rm1[i]='0';
		else
		Rm1[i]='1';
	} 	
	    
	/*	cout<<endl<<"EP��չ����Կ��λ�����Rm1Ϊ��"<<endl;
		for(int i=0;i<8;i++)
			cout<<Rm1[i];  */
	int x1,y1,x2,y2;
	x1=(Rm1[1]-'0')*2+(Rm1[2]-'0');//S0���滻 
	y1=(Rm1[0]-'0')*2+(Rm1[3]-'0');
	x2=(Rm1[5]-'0')*2+(Rm1[6]-'0');//S1���滻 
	y2=(Rm1[4]-'0')*2+(Rm1[7]-'0');
	int s0=S0[y1][x1];
	int s1=S1[y2][x2];
	Rm1[0]=intz((s0/2)%2); //Rm1����SBoxes�滻 
	Rm1[1]=intz(s0%2);
	Rm1[2]=intz((s1/2)%2); 
	Rm1[3]=intz(s1%2);
	/*	cout<<"����S�к��Rm1Ϊ��"<<endl;
		for(int i=0;i<4;i++)
			cout<<Rm1[i]; */
	char Rm2[4];
	for(int i=0;i<4;i++){//Rm1����P4�û���Rm2�ٺ�Lm����� ���ΪLm1 
		Rm2[i]=Rm1[(P4[i]-1)];
	/*	cout<<"P4�û����RM1Ϊ��"<<Rm2[i]<<endl; */
		if(Lm[i]==Rm2[i])
		Lm1[i]='0';
		else
		Lm1[i]='1';
	}
	/*	cout<<"����P4�û���Lm����Lm1Ϊ��"<<endl;
		for(int i=0;i<4;i++)
			cout<<Lm1[i]; */
}

// ��ASCII�ַ���ת��Ϊ�������ַ���
void asciiToBinaryString(const char *ascii, char *binary) {
    for (int i = 0; i < 8; i++) {
        char c = ascii[i];
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + j] = ((c >> (7 - j)) & 1) ? '1' : '0';
        }
    }
}

// ���������ַ���ת��ΪASCII�ַ���
void binaryStringToAscii(const char *binary, char *ascii) {
    for (int i = 0; i < 8; i++) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            c = (c << 1) | (binary[i * 8 + j] - '0');
        }
        ascii[i] = c;
    }
}



int main(){
	int choose;
	cout<<"Please enter 1 for encryption, 2 for decryption�� 3 for finding a key and 4 FOR ASCII"<<endl;
	cin>>choose;
    //���� 
	if(choose==1){
	char mkey[10],m[8],temp[8];//����Կ�����ģ���ʱ���� 
	char k1[8],k2[8];//����ԿK1��K2 
    char Rm[4],Lm1[4];//�ֶ�
    while(cin>>mkey>>m){
		key(mkey,k1,k2);//��������Կ K1 K2 
		change(m,temp,IP,8);//����IP�û� 
		DES(temp,k1,Rm,Lm1);//��һ��ѭ��,����Rm��Lm1 
	//	cout<<"��һ��ѭ���õ���RmΪ��"<<Rm[0]<<Rm[1]<<Rm[2]<<Rm[3]; 
	//	cout<<"��һ��ѭ���õ���Lm1Ϊ��"<<Lm1[0]<<Lm1[1]<<Lm1[2]<<Lm1[3]; 
		char m1[8],Rm1[4],Lm11[4]; 
		merge(m1,Rm,Lm1,8);//��Rm��Lm1���һ����ϳ�m1  
		DES(m1,k2,Rm1,Lm11);//�ڶ���ѭ��,����Rm1��Lm11 
	//	cout<<"�ڶ���ѭ���õ���Rm1Ϊ��"<<Rm1[0]<<Rm1[1]<<Rm1[2]<<Rm1[3]; 
	//	cout<<"�ڶ���ѭ���õ���Lm11Ϊ��"<<Lm11[0]<<Lm11[1]<<Lm11[2]<<Lm11[3]; 
		char mw[8],mw1[8];//���ս������Ϊmw1 
		merge(mw,Lm11,Rm1,8);//��Rm1��Lm11�ϳ�mw 
	/*	cout<<"IP��1�û�ǰ��mwΪ��"<<endl;
			for(int i=0;i<8;i++)
			cout<<mw[i];
			cout<<endl; */
		change(mw,mw1,IP_1,8);//mw ����IP-1�û����õ�����mw1 
		for(int i=0;i<8;i++)
			cout<<mw1[i];
		cout<<endl;
	    }
    }
    //���� 
    if(choose==2){
    char mkey[10],m[8],temp[8];//����Կ�����ģ���ʱ���� 
	char k1[8],k2[8];//����ԿK1��K2 
    char Rm[4],Lm1[4];//�ֶ�
    while(cin>>mkey>>m){ //�����m��Ϊ���� 
		key(mkey,k1,k2);//��������Կ K1 K2 
		change(m,temp,IP,8);//����IP�û� 
		DES(temp,k2,Rm,Lm1);//��һ��ѭ��,����Rm��Lm1 ����k2 
		char m1[8],Rm1[4],Lm11[4]; 
		merge(m1,Rm,Lm1,8);//��Rm��Lm1���һ����ϳ�m1  
		DES(m1,k1,Rm1,Lm11);//�ڶ���ѭ��,����Rm1��Lm11 ����k1 
		char mw[8],mw1[8];//���ս������Ϊmw1 
		merge(mw,Lm11,Rm1,8);//��Rm1��Lm11�ϳ�mw 
		change(mw,mw1,IP_1,8);//mw ����IP-1�û����õ�����mw1 
		for(int i=0;i<8;i++)
			cout<<mw1[i];
		cout<<endl;
	    }
    }
    
        if(choose==3){
        bool get = false; //ȷ���Ƿ��ҵ�����Կ 
        char m[8],mw[8],temp[8];//���ģ����ģ���ʱ���� 
        char mkey[10] = {'0','0','0','0','0','0','0','0','0','0'};//��ʼ����ԿȫΪ0 
	    char k1[8],k2[8];//����ԿK1��K2 
        char Rm[4],Lm1[4];//�ֶ� 
		cout<<"Please enter the plaintext:"<<endl;
		cin>>m;
		cout<<"Please enter the ciphertext:"<<endl;
		cin>>mw; 
        int sum=0;
        while(sum!=11)
		{
	    	for(int i=0;i<10;i++)
            {
            	if(mkey[i]=='0'){
            	mkey[i]='1';
            	break;
	            }
        	    if(mkey[i]=='1'){
        		mkey[i]='0';
		    	}
	        
            } //����������ȫ���� 
            sum=0;
            for(int i=0;i<10;i++)
	    	{
                if(mkey[i]=='1')sum++;
	    	}
	
	    	//��ʼ���ԣ������ļ��ܿ�����Ƿ��������� 
	     	key(mkey,k1,k2);//��������Կ K1 K2 
	    	change(m,temp,IP,8);//����IP�û� 
	    	DES(temp,k1,Rm,Lm1);//��һ��ѭ��,����Rm��Lm1 
	    	char m1[8],Rm1[4],Lm11[4]; 
	    	merge(m1,Rm,Lm1,8);//��Rm��Lm1���һ����ϳ�m1  
	    	DES(m1,k2,Rm1,Lm11);//�ڶ���ѭ��,����Rm1��Lm11 
	    	char mw1[8],mw11[8];//���ս������Ϊmw11 
	    	merge(mw1,Lm11,Rm1,8);//��Rm1��Lm11�ϳ�mw1
	    	change(mw1,mw11,IP_1,8);//mw1 ����IP-1�û����õ�����mw11 
	    	int count=0;
	    	for(int i=0;i<8;i++) //�ȶԼ��ܳ������ĺ���������� 
			{
				if(mw[i]==mw11[i])count+=1;
			}
			if(count==8)
			{
				cout<<"����ɹ�����ԿΪ��"<<endl;
				get = true;
				for(int i=0;i<10;i++)
			    cout<<mkey[i];
			    cout<<endl;
			}
			if(sum==10)sum+=1; //ȫ���н������� ����ȫΪ1������ 
	    		
        }
        if(get == false) cout<<"�޶�Ӧ��Կ";
    
        }
        
    // �ַ������� 
    if (choose == 4) {
    	cout<<"Enter 1 for encryption, 2 for decryption"<<endl;
    	int choose1;
    	cin>>choose1;
        char mkey[10], temp[8],cut[8]; // ����Կ����ʱ����,�и����� 
        char k1[8], k2[8]; // ����Կ K1��K2
        char Rm[4], Lm1[4]; // �ֶ�
        cin>>mkey;
        string mm; //�����ַ�����������ͳ��������ַ�����  ��/���� 
        cin>>mm;
        int length =mm.length(); //������ַ����� 
       // cout<<length<<endl;
        char m[length]; //�ַ���ת�ַ����� 
        strcpy(m, mm.c_str());
        
       
	       //��ASCII����ת��Ϊ�������ַ���
            char binaryM[length*8];
            asciiToBinaryString(m, binaryM);
         //   cout<<"�ַ�����/����ת���õ��Ķ���������Ϊ��";
         //  	for(int i=0;i<length*8;i++)
		//	cout<<binaryM[i];
		//    cout<<endl;
            
            int k=0;
            int flag=0;
            //����8λһ����м��ܣ��ֱ����
			key(mkey,k1,k2);//��������Կ K1 K2 
			while(flag<length*8)
			{
		//	if(flag!=0)k+=1;
			for(int i=0;i<8;i++)
			{
				cut[i]=binaryM[k];
			    k++;	
			} //�и�������8λ 
        //    cout<<"�������������IP�û��õ���cutΪ��";
        //   	for(int i=0;i<8;i++)
		//	cout<<cut[i];
		//    cout<<endl;
            change(cut, temp, IP, 8);   //���� IP�û�
            if(choose1==1)
	    	DES(temp,k1,Rm,Lm1);//��һ��ѭ��,����Rm��Lm1 
	    	else
	    	DES(temp,k2,Rm,Lm1);//��һ��ѭ��,����Rm��Lm1
	    	
			char m1[8],Rm1[4],Lm11[4]; 
	     	merge(m1,Rm,Lm1,8);//��Rm��Lm1���һ����ϳ�m1  
	     	if(choose1==1)
	    	DES(m1,k2,Rm1,Lm11);//�ڶ���ѭ��,����Rm1��Lm11 
	    	else
	    	DES(m1,k1,Rm1,Lm11);//�ڶ���ѭ��,����Rm1��Lm11 
	    	char mw[8],mw1[8];//���ս������Ϊmw1 
	    	merge(mw,Lm11,Rm1,8);//��Rm1��Lm11�ϳ�mw 
	    	change(mw,mw1,IP_1,8);//mw ����IP-1�û����õ�����mw1 
	    	int sum1=0;
	    //	cout<<"��/���ܺ�õ��Ķ���������Ϊ��";
	    	//��8λ����������תΪ��Ӧ���ַ� 
	    	int mw1_int;
	    	for(int i=0;i<8;i++)
	    	{
		//	cout<<mw1[i];
			if(mw1[i]=='0')mw1_int=0;
			else mw1_int=1;
			sum1+=mw1_int*(pow(2,7-i));
	     	}  
		  //  cout<<endl;
          //  cout<<"����int/����int"<<sum1<<endl;
          //  cout<<"����char/����char"<<char(sum1)<<endl;
            cout<<char(sum1);
			/*if(sum1<=127)cout<<"����char/����char"<<char(sum1)<<endl;
			else cout<<"����char/����char"<<char(sum1%127)<<endl; */
            
            /*
            //�����ܺ�Ķ����ƽ��ת��ΪASCII����
            char encryptedAscii[8];
            binaryStringToAscii(mw1, encryptedAscii);

            // ������ܺ��ASCII����
            cout << "����������ת��Ϊ�ַ����ģ� " << encryptedAscii << endl; 
            */
            flag+=8;
			}

	
        } 
    
    return 0;
}


