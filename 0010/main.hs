-- Although this algorithm is quite slow, it performs well enough
-- such that it generates all primes below 2M. It works by using
-- a 'try and error' approach.

module Main where

primes :: [Integer]
primes = 2 : filter (isPrime primes) [3,5..]
  where isPrime (p:ps) n = p*p > n || n `rem` p /= 0 && isPrime ps n

main = do
  (putStrLn . show . sum) primesLowerThan2M where
    primesLowerThan2M = takeWhile (<2000000) primes
