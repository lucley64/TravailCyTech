module Document where

newtype Document title kws =  String [String]

searchByKeyword :: String -> [Document a] -> [Document a]
searchByKeyword kw docs = filter (\(String docKw) -> elem kw docKw) docs