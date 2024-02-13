{-# OPTIONS_GHC -Wno-missing-export-lists #-}

module Pupil where

data Pupil = Pupil {name :: String, surname :: String, notes :: [Double]}

data ReportCard = ReportCard {nameCpt :: String, mean :: Double}

reports :: [Pupil] -> [ReportCard]
reports = map (\(Pupil n s nts) -> ReportCard {nameCpt = n ++ s, mean = sum nts / fromIntegral (length nts)})