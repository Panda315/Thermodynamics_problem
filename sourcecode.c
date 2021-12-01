#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float convert_pressure();
float convert_volume();
float calculation();
float p1=0,p2=0,v1=0,v2=0,g=1.3;

int main()
{

  printf("THE UNITS NEEDS TO BE STANDARD UNITS.\nPLEASE CONVERT THE UNITS INTO STANDARD UNITS IF NEEDED.\nEVEN THE HIGHER UNITS SHOULD BE CONVERTED.\n");
  printf("\nPLEASE MAKE SURE THE UNITS OF PRESSURE AND VOLUME ARE IN PASCAL AND CUBIC METRE RESPECTIVELY.\n");

  unitsconversion:              //Beginning of units conversion loop
      {
          int unitsresponse_1=0;
  printf("\nDO YOU NEED TO CONVERT THE UNITS :\n- PRESS 1 FOR YES\n- PRESS 0 FOR NO\n");
  scanf("%d",&unitsresponse_1);

        if(unitsresponse_1==1)
        {
            int unitsresponse_2=0;
            printf("\nPRESS THE APPROPRIATE KEY:\n1) CONVERT PRESSURE\n2) CONVERT VOLUME\n");
            scanf("%d",&unitsresponse_2);

            if(unitsresponse_2==1)
                {
                    convert_pressure();
                    goto unitsconversion;
                }

            else if(unitsresponse_2==2)
                {
                    convert_volume();
                    goto unitsconversion;
                }

            else
            {
                printf("INVALID INPUT !!");
                goto unitsconversion;
            }
        }
      } //End of units conversion loop


    //if there is no conversion of units
    if(p1==0)
    {
        printf("\n\nENTER INITIAL PRESSURE : ");
        scanf("%f",&p1);
    }

    if(p2==0)
    {
        printf("\n\nENTER FINAL PRESSURE : ");
        scanf("%f",&p2);
    }

    if(v1==0)
    {
        printf("\n\nENTER INITIAL VOLUME : ");
        scanf("%f",&v1);
    }

    //function calculation solves the problem
    calculation();


    return 0;
}

float convert_pressure(){

    float pressure=0;

    here:
    printf("\n\nEnter the value of pressure only:");
    scanf("%f",&pressure);

    int n;
    printf("\n\nPRESS THE APPROPRIATE KEY : \n");
    printf("1) Atmospheric pressure(atm) to pascal(pa) \n2) Torr(Torr) to pascal(pa) \n3) Bar(bar) to pascal(pa) \n4) Kilo Pascal(KPa) to pascal(pa) \n5) Exit\n");
    scanf("%d",&n);

    float a=0;
    if(n==1)
    {
        a=pressure*101325;
        goto last;
    }
    else if(n==2)
    {
      a=pressure*133.322;
        goto last;
    }
    else if(n==3)
    {
        a=pressure*100000;
        goto last;
    }
    else if(n==4)
    {
        a=pressure*1000;
        goto last;
    }
    else if(n==5)
    {
        return 0;
    }
    else
    {
        printf("INVALID INPUT !!");
        goto here;
    }

    int temp=0;
    last:
    printf("\nSTORE THE VALUE AS :\n");
    printf("1)Initial Pressure \n2)Final Pressure \n");
    scanf("%d",&temp);

        if(temp==1)
            p1=a;
        else if(temp==2)
            p2=a;
        else
        {
         printf("\nINVALID INPUT !!!\n");
         goto last;
        }
        return 0;
}

float convert_volume()
{
        float volume=0;

    here:
    printf("\n\nEnter the value of volume only: ");
    scanf("%f",&volume);

    int n;
    printf("\n\nPRESS THE APPROPRIATE KEY : \n");
    printf("1) Barell to cubic metre \n2) Litre to cubic metre \n3) Gallon to cubic metre \n4) Cubic centimetre to cubic metre \n5) Cubic mililitre to cubic metre \n6) Cubic inch to cubic metre \n7) Cubic foot to cubic metre \n8) Exit\n");
    scanf("%d",&n);

    if(n==1)
    {
        v1=volume*0.15898729493;
        return 0;
    }
    else if(n==2)
    {
        v1=volume*0.001;
        return 0;
    }
    else if(n==3)
    {
        v1=volume*0.00378541;
        return 0;
    }
    else if(n==4)
    {
        v1=volume*0.000001;
        return 0;
    }
    else if(n==5)
    {
        v1=volume*0.000000001;
        return 0;
    }
    else if(n==6)
    {
        v1=volume/61024;
        return 0;
    }
    else if(n==7)
    {
        v1=volume*0.0283168;
        return 0;
    }
    else if(n==8)
    {
        return 0;
    }
    else
    {
        printf("INVALID INPUT !!");
        goto here;
    }

}

float calculation()
{
    float a=0;

    a=(p1*pow(v1,g))/p2 ;
    v2=pow(a,1/g);

    float w=((p1*v1)-(p2*v2))/0.3 ;

    printf("\n\nTHE WORK DONE ON THE PISTON BY THE GAS PRESSURE IS %.2f J.",w);

    return 0;
}