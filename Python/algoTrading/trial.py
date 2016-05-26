import numpy as np
import pandas as pd
import pandas.io.data as web

goog = web.DataReader('GOOG', data_source='google', start = '4/23/2016', end = '5/23/2016')
print goog.tail()


goog['Log_Ret'] = np.log(goog['Close'] / goog['Close'].shift(1))
goog['Volatility'] = pd.rolling_std(goog['Log_Ret'], window=252) * np.sqrt(252)

%matplotlib 
goog[['Close', 'Volatility']].plot(subplots=True, color='blue', figsize=(8, 6))
# #parameters 
# S0 = 100 # initial index level
# K = 105 # strike price
# T = 1.0 # time-to-maturity
# r = 0.05 # riskless short rate
# sigma = 0.2 # volatility


# I = 100000 # number of simulations

# # valuation algorithm
# z = random.standard_normal(I) # pseudorandom numbers
# ST = S0 * exp((r-0.5 * sigma ** 2) * T + sigma * sqrt(T) * z)

# # index value at maturity
# hT = maximum(ST - K, 0) # innner value maturity
# C0 = exp(-r * T) * sum(hT)/ I # Monte Carlo estimator

# print "Value of call Option %5.3f" % C0