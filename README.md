*This project has been created as part of the 42 curriculum by nkato, kkajikaw.*

# push_swap

## Description（概要）

ARG=$(shuf -i 1-5000 -n 500); ./push_swap --bench --complex $ARG |./checker_linux $ARG

ARG="-3 -2"; ./push_swap $ARG | ./checker_linux $ARG
zsh じゃなくて bashで実行する　さもないとARGが空白入りの文字列として認識されてしまうため

3数字の場合分け分からん！！！！あとdouble型の出力かけてない


## Instructions（手順）
➀ft_printf フォルダにて以下のコマンドを使用する
```bash
make
#ft_printfフォルダ内に含まれるcファイルをコンパイルし、オブジェクトファイルとともに"libftprintf.a"ファイルを作成する
```
なお、他にもこれらのコマンドを使用することができます。
```bash
make clean
#オブジェクトファイルを削除する

make fclean
#オブジェクトファイルと"libftprintf.a"を削除する

make re
#make fclean を行ったあと make を行う
```

②ヘッダーをインクルードし、ライブラリをリンクする
```c
include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror yourprogram.c -L. -lftprintf
```

## ディレクトリ構成
```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_printf_char.c
├── ft_printf_hex.c
├── ft_printf_nbr.c
├── ft_printf_ptr.c
├── ft_printf_str.c
└── README.md
```

## アルゴリズム
詳細な説明と選定理由を記載
### simple sort
### medium sort
### complex sort
### 



## Resources（参考資料）
- ft_printfの課題PDF（42）
- 42Norm（42）

printf をここから持ってきたよみたいなことを書くスペース


### AIの使用について
ft_printf の作成にあたり、生成AI（Claude）を使用しました。これはあくまで補助的に使われており、全てのコードは筆者の理解のもとに作成されています。生成AIの使用箇所は以下の通りです。
- テストケースの確認およびテストコードの作成補助
- c言語の仕様理解
- デバッグの補助
- Makefileおよびmarkdownの仕様理解




