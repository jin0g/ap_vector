# ap_vector

`ap_vector` は、任意のビット幅の `ap_int` の配列を扱うためのクラスです。

## 概要

`ap_vector` クラスは、以下の機能を提供します。

- `ap_int` の長いビット幅の型と `ap_vector` 型の配列を、容易に行ったり来たりできます。
- `ap_vector` 同士や `ap_vector` と `ap_int` に対する四則演算および左右シフト演算が行えます。
- 異なるビット幅の `ap_vector` への型変換ができます。

## 使用方法

### ap_vector の定義と初期化

```c++
#include "ap_int.h"
#include "ap_vector.h"

// 例: 4要素の8ビット幅のap_vectorを作成
ap_uint<32> value = 0x12345678;
ap_vector<4, 8> list = value;
```

### 要素へのアクセスと変更

```c++
// 要素へのアクセス
ap_int<8> elem = list[0];

// 要素の変更
list[1] = 0xAB;
```

### 四則演算および左右シフト演算

```c++
// ap_vectorと定数の演算
auto list_add1 = list1 + 1234;

// ap_vectorとap_int形の演算
ap_int<32> item = 4321;
auto list_add2 = list1 + item;

// ap_vector同士の演算
auto list_add3 = list1 + list2;
```

このように + 演算子を用いて ap_vector に対する演算を行うことができます。
その他にも、以下の演算が利用できます。

```c++
足し算: list1 + list2
引き算: list1 - list2
掛け算: list1 * list2
割り算: list1 / list2
あまり: list1 % list2
左シフト: list1 << list2
右シフト: list1 >> list2
```

### 型変換

```c++
// ap_uint から ap_vector への変換
ap_uint<32> value = 0x12345678;
ap_vector<4, 8> list = value;

// ap_vector から ap_uint への変換
ap_uint<32> result = list;

// 異なるビット幅の ap_vector への変換
ap_vector<4, 16> list2 = ap_vector<4, 16>(list1);
```

## 注意点
- ap_intはap_vectorと双方向にキャストできないため、ap_uintを使用してください。
- 適切に#pragmaを使用しないと、最適なパフォーマンスが得られません。
- ほとんどの場合で#pragma HLS pipelineの中でap_vectorを使用することが推奨されます。

## サンプルコード

`main.cc` にサンプルコードがあります。機能を網羅するテストコードが記載されていますので、実装の詳細や使い方を理解するために参考にしてください。
