%%this is just me trying to make help but failing continuously 
function output2 = Calculator()
    
num1 = input('\nplease enter the first  ','s');
num2 = input('please enter the second  ','s');
operation = input('please eneter the operation ','s');
num1 =str2num(num1 );
num2 =str2num(num2 );
output2 =0 

switch(operation)   
    case '+'
        output2 = num1+num2
        fprintf('The result of %d %s %d is : %d',num1,operation,num2,num1+num2);    
    case '-'
        output2 = num1-num2
        fprintf('The result of %d %s %d is : %d',num1,operation,num2,num1-num2);
    case '*'
        output2 = num1*num2
        fprintf('The result of %d %s %d is : %d',num1,operation,num2,num1*num2);
    case '/'
        if num2 == 0
         fprintf('you cannot divide by zero')           
        else
        output2 = num1/num2 
        fprintf('The result of %d %s %d is : %d',num1,operation,num2,num1/num2);
        end
end

end

