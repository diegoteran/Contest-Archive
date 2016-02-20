main = do
    a <- getLine
    str <- getLine
    let str1 = map read $ words str :: [Int]
        even = sum [x | x <- str1, mod x 2 == 0]
        odd = sum [x | x <- str1, mod x 2 == 1]
    putStrLn (show(even) ++ " " ++ show(odd))

