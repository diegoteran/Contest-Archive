main = do
    str <- getLine
    let x = sum (map read $ words str :: [Int])
    putStrLn $ show x 
