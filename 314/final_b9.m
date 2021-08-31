% 18101009/ hasan tahsin rafsan
% question b set 9

ref =09; 

f=@(x) (e^x-3*x^2);
fprime=@(x) (e^x-6*x);

iter=2;
x_old=3;
matrix=zeros(10,4);

matrix(1,1) =0;
matrix(1,2) =4;
matrix(1,3) =NaN;
matrix(1,4) =NaN;

while iter<=11
    x_new=x_old-f(x_old)/fprime(x_old);
    matrix(iter,1) =iter-1;
    matrix(iter,2) = x_new;
    eror= abs((abs(x_new-x_old)/x_new)*100);
    
    
    matrix(iter,3) = eror;
    sig = 0;
    if eror>5
        sig=0;
    endif


    if eror>0.5 && eror<=5
        sig=1;
    endif


    if eror>0.05 && eror<=0.5
        sig=2;
    endif


    if eror>0.005 && eror<=0.05
        sig=3;
    endif


    if eror>0.0005 && eror<=0.005
        sig=4;
    endif


    if eror>0.00005 && eror<=0.0005
        sig=5;
    endif


    if eror>0.000005 && eror<=0.00005
        sig=6;
    endif
    
    
    
    matrix(iter,4) = sig;
    
    x_old = x_new;
    iter=iter+1;
endwhile


disp(matrix)