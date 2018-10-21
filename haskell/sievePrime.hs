sievePrime :: Int -> [Int]
sievePrime n = [x | x <- [2..n],
                and [mod x y /= 0 | y <- [2..(floor . sqrt . fromIntegral) x]]]
