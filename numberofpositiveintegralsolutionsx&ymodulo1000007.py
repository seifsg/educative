'''

Find the no of positive integral solutions for the equations (1/x) + (1/y) = 1/N! (read 1 by n factorial) 
Print a single integer which is the no of positive integral solutions modulo 1000007.

Input:
N 
Output:
Number of positive integral solutions for (x,y) modulo 1000007
Constraints:
1 <= N <= 10^6 
Sample Input00:
1

Sample Output00:
1

 

Sample Input01:

32327

Sample Output 01:

656502

Sample Input02:

40921

Sample Output 02:

686720 '''


'''
This is challenge was a bit hard for me hehe
So I had to search for help online , I got the java solution , but with me being not familiar with java I had some difficulties translating to a familiar langauge
http://sharathpan.wordpress.com/2012/05/17/interview-street-equations-solution/

Anyway , this is much more simple to read and understand . '''

from math import *
def isprime(n):
    for i in xrange(2,(n/2)+1):
        if (n % i == 0):
            return False         
    return True

def primes(n):
    m=[]
    for i in xrange(2,n+1):
        if isprime(i):
            m.append(i)
    return m

def mul(i,n):
    m = 0
    while(n>0):
        m += n/i
        n /= i
    return (2*m) + 1
n = int(raw_input())

m=primes(n)
#print m 
c=1;mu = []
for i in m:
    mu.append(mul(i,n))

for i in mu:
    c *= i
    
print  c % 1000007
