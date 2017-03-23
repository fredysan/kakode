open Require.Promise;
open Require.Vscode;

let edit action =>
  fun editor state => {
    editor
    |> TextEditor.edit (fun builder => action builder editor)
    |> Promise.then_ (fun _ => state)
  };

let mode mode =>
  fun _ _ =>
    Promise.resolve State.{ mode: mode };

let selection action =>
  fun editor state => {
    TextEditor.setSelection editor (action (editor |> TextEditor.selection) editor);
    Promise.resolve state
  };
