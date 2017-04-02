open Require.Promise;
open Require.Vscode;

type t = textEditor => State.t => Promise.t State.t unit;

let then_ g f  =>
  fun editor state => f editor state |> Promise.andThen (g editor);