
int main()
{
    double x[1024] = {};
    double y[1024] = {};
    double signalToFilter []={1,2,3,4,5,6,7,8,9,10};
    double convolutionResult[1024*2-1];
    double correlationResult[1024*2-1];
    double filterCoefficients[35] ={-0.00258031145400345,0.00400383977344830,0.00187900347123028,-0.0141749533787536,0.0184962669560903,-0.00372491258658280,-0.0155334051471967,0.0106146900126776,0.0177784694188298,-0.0276799030545178,-0.00788639905734323,0.0458431501715044,-0.0169260699886628,-0.0635147932659970,0.0741627904983327,0.0760489715629139,-0.306935782734153,0.419376976304175,-0.306935782734153,0.0760489715629139,0.0741627904983327,-0.0635147932659970,-0.0169260699886628,0.0458431501715044,-0.00788639905734323,-0.0276799030545178,0.0177784694188298,0.0106146900126776,-0.0155334051471967,-0.00372491258658280,0.0184962669560903,-0.0141749533787536,0.00187900347123028,0.00400383977344830,-0.00258031145400345};
    double filteredSignal[44];
   // convolve(x,y,convolutionResult,1024,1024);
   // printf("the convolution is : \n");
   // printArray(convolutionResult,1024*2-1);
   // printf("the correlation is : \n");
    correlate(x,y,correlationResult,1024,1024);
   //printArray(correlationResult,1024*2-1);
   findIndexofMaximum(correlationResult,1024*2-1);
    //printf("the maximum of the correlation is at %i . \n",findIndexofMaximum(correlationResult,1024*2-1));
   // printf("Hello world!\n");
   // filterOut(signalToFilter,filterCoefficients,filteredSignal,10,35);
    //printArray(signalToFilter,10);
    //printf("\n");
   // printArray(filteredSignal,35);
    return 0;
}

void printArray(double array[], int length)
{
    int i;
    printf("The signal is : ");
    for(i=0;i<length;i++)
        printf(" %f ",array[i]);
    printf("\n");
}

void convolve (double x_[], double y_ [] , double z[], int len_x, int len_y)
{
    double x[len_x+len_y -1];
    double y[len_x+len_y -1];
    int i ,j;
    for(i =0; i<len_x;i++)
    {
        x[i]=x_[i];
        y[i]=y_[i];
    }

    // zero padding
    for(i=len_x;i<=len_x+len_y-1;i++)
        x[i]=0;
    for(i=len_y;i<=len_x+len_y-1;i++)
        y[i]=0;

    //convolution
    for(i=0;i<len_x+len_y-1;i++)
        {
            z[i]=0;
            for(j=0;j<=i;j++)
                {
                    z[i]=z[i]+(x[j]*y[i-j]);
                }
        }
}

void correlate (double x[], double y[] , double z[], int len_x, int len_y)
{
// flip y[]
    double yFlipped [len_y];
    int i;
    for(i=0;i<len_y;i++)
        yFlipped[i]=y[len_y-i-1];

    // call convolution
    convolve(x,yFlipped,z,len_x,len_y);


}

int findIndexofMaximum(double array[], int len_array)
{
    int maximum = array[0];
    int index =0;
    int i;
    for(i=0;i<=len_array;i++)
    {
        if(array[i]>=maximum)
        {
            maximum = array[i];
            index = i;
        }


    }
    return index;
}

void filterOut(double input [],double filter[],double output[],int len_input,int len_filter)
{

    // find response to filter i.e. convolve with filter.
    convolve(input,filter,output,len_input,len_filter);

}
