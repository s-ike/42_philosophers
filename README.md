# 42_philosophers
食事する哲学者の問題([Wiki](https://ja.wikipedia.org/wiki/%E9%A3%9F%E4%BA%8B%E3%81%99%E3%82%8B%E5%93%B2%E5%AD%A6%E8%80%85%E3%81%AE%E5%95%8F%E9%A1%8C]))に似た問題

## Rules
哲学者の振る舞い
1. １本目のフォークを取る
2. ２本目のフォークを取る
3. 食事する
4. 2つのフォークを落とし眠る
5. 思索する

## Usage
スレッドとミューテックスを使用するバージョン
```
cd philo
make
./philo 哲学者の人数 死ぬまでの時間 食事に費やす時間 睡眠に費やす時間 [それぞれの哲学者が最低何回食事するか]
```
フォークとセマフォを使用するバージョン
```
cd philo_bonus
make
./philo 哲学者の人数 死ぬまでの時間 食事に費やす時間 睡眠に費やす時間 [それぞれの哲学者が最低何回食事するか]
```
## Demo
<img width="401" alt="スクリーンショット 2022-02-05 14 02 21" src="https://user-images.githubusercontent.com/13024418/152629398-67a6e855-5c3d-4a6b-9081-336eb7fbbe98.png">
