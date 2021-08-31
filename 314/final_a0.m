% 18101009/ hasan tahsin rafsan
% question a set 0

ref = 09;

function CDD(x,i)

    del_x = 2;
    x2=x+del_x;
    x3=x-del_x;

    y2 = 3*e^(2.5*x)+sin(x)+2;
    y3 = 3*e^(2.5*x)+sin(x)-2;    
    y1 = 3*e^(2.5*x)+sin(x);

    CDD = (y2-y3)/2*del_x;

    disp(['The value of CDD is: ',num2str(CDD), ' For x',num2str(i)]);
    
endfunction

CDD(2.12,0)
CDD(4.12,1)
CDD(6.12,2)

x = 2.12:2:6.12;
y = 3*e.^(2.5*x)+sin(x);
plot(x,y)