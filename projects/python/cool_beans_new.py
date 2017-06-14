
# coding: utf-8

# In[1]:

import this


# In[16]:

beans = input('I say "cool." How do you respond?\nResponse: ')
beans = beans.lower()

while beans != 'beans':
        print('Incorrect')
        beans = input('Again, I say "cool." How do you respond?\nResponse: ')
        beans = beans.lower()

print('Cool beans bro.')

