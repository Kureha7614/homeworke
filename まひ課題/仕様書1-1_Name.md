# ゲーム仕様書

記入者：  岩本徠希<br>
記入日：  09/18<br>
対象バージョン：  visual studio2026

---

## 1. ゲーム概要

### 1.1 ゲームの目的

（敵を倒して、ドロップしたアイテム（スクラップ）をクラフト（ボム）を使いミッション（クリア条件）をクリアしてゴールを目指す）


### 1.2 クリア条件

（敵をせん滅しボムを作成して壁をボムで破壊し、ターゲットにインタラクトする）


### 1.3 ゲームオーバー条件

（プレイヤーのHPが０になること）


## 2. 画面遷移

### 2.1 シーン一覧

| シーン | 役割 | 遷移先 | 遷移条件 |
|---|---|---|---|
| TitleScene |タイトル画面の表示  |GameScene  | キーボードでEnterを押すか、Xboxコントローラー（以下PAD）でAボタンを押すか |
| GameScene | ゲーム画面の表示 |  ResultScene| ミッションがクリアか、ゲームオーバーで表示 |
| ResultScene | リザルト画面の表示 |  TitleScene<br>GameScecn|  EnterかPADのAを押すとゲーム画面<br>EscかPADのBを押すとタイトル画面に移行|

### 2.2 Restart時の生成・破棄

（・敵の生成  
・壁の生成  
・プレイヤーの初期化  
・ミッションの達成数を０にする  
・プレイ時間の破棄  
・入手したアイテムの破棄  
・カメラの位置を0,0にも戻す）


## 3. 操作仕様

| 操作 | キーボード | コントローラー | ゲーム内の効果 |
|---|---|---|---|
| 移動 | wasdと矢印キー | PADのひだりスティック | プレイヤーの移動 |
| 攻撃 | z | PADのA | 敵に攻撃 |
| 回避 |x  | PADのB |  回避|
| インタラクト | e |  PADのY| プレイヤーが行う特定の動作 |
| Gadget使用 | c | PADのR | ボムの配置 |
| 工作画面 |  q|  PADのL|  ボムのクラフト|
| ポーズ |  esc|  Strat| 一時停止 |

## 4. ゲームプレイループ

開始からResultまでを、処理の条件を含めて記入してください。

1. 
2. 
3. 
4. 
5. 
6. 
7. 
8. 

## 5. Player仕様

### 5.1 状態一覧

| 状態 | 開始条件 | 終了条件 | 状態中の挙動 |
|---|---|---|---|
| Idle |actionTimer_が0.0f以下ならば  |  | 動いていない |
| Move | actionTimer_が0.0f以下ならば |  | 移動方向に190.0fで動く |
| Attack |  攻撃ボタンを押すかつactionTimer_が0.0f以下ならば |  | 敵を攻撃する |
| Dodge |回避ボタンを押すかつactionTimer_が0.0f以下ならば  |  | 移動方向に380.0Fで動く |
| Damage | invincibilityTimer_が0.0f以下ならば |  | ダメージを食らう |
| Dead | state_がDeadになっていたら |  | 脂肪 |

### 5.2 攻撃判定

（プレイヤー向いている向きに（1.0f，0.0f）の判定）


### 5.3 被ダメージと無敵時間

（残りHPからDamageを引いて、invincibilityTimer_にDamageInvincibilityDurationの（1.0f）の無敵時間を足す  
DodgeはinvincibilityTimer_にDodgeInvincibilityDuration（0.3f）の無敵時間を足す）


## 6. Enemy／EnemyAI仕様

### 6.1 視覚判定の順序

1. 
2. 
3. 

### 6.2 警戒状態

| 状態 | Awareness条件 | 移動先 | 表示色 |
|---|---|---|---|
| Patrol |  |  |  |
| Suspicious |  |  |  |
| Alert |  |  |  |
| Chase |  |  |  |

### 6.3 AI更新頻度と遠距離時の処理

（ここに記入）


## 7. Item／Inventory／Craft仕様

### 7.1 WorldItemとInventoryの違い

（ここに記入）


### 7.2 Bombレシピ

| 必要素材 | 必要数 | 完成物 | 完成数 |
|---|---:|---|---:|
| スクラップ |２  | ボム |  １|

### 7.3 工作失敗時の挙動

（ここに記入）


## 8. Bomb／WorldEffect仕様

| 項目 | 値または挙動 |
|---|---|
| Fuse |  |
| Explosion radius |  |
| Damage |  |
| Enemyへの効果 |  |
| BreakableWallへの効果 |  |

## 9. Mission仕様

| MissionState | 進行条件 | 次の状態 |
|---|---|---|
| ReachTarget |  |  |
| ReachExtraction |  |  |
| Cleared |  |  |

## 10. 更新順序

`Gameplay::UpdatePlaying`を基準に記入してください。

1. 
2. 
3. 
4. 
5. 
6. 
7. 
8. 
9. 
10. 

## 11. 生成と削除

### 11.1 フレーム中に要求だけを記録する対象

（ここに記入）


### 11.2 フレーム末尾に確定する理由

（ここに記入）


## 12. クラス責務・所有関係

| クラス | 主な責務 | 所有する対象 | 所有しない連携対象 |
|---|---|---|---|
| GameApplication |  |  |  |
| SceneManager |  |  |  |
| GameScene |  |  |  |
| Gameplay |  |  |  |
| EnemyManager |  |  |  |
| ItemManager |  |  |  |
| CraftSystem |  |  |  |
| CollisionSystem |  |  |  |
| Mission |  |  |  |

## 13. UIデータフロー

（Gameplay、HudViewModel、GameHudの関係を記入）


## 14. デバッグ表示

| 表示項目 | 意味 | 何の確認に使うか |
|---|---|---|
| Enemy count |  |  |
| Updated enemies |  |  |
| Collision candidates |  |  |

## 15. 不明点・確認事項

1. 
2. 
3. 

## 16. 問題点と改善案

| 優先度 | 現在の問題 | 改善案 | 影響範囲 |
|---|---|---|---|
|  |  |  |  |
|  |  |  |  |
|  |  |  |  |
