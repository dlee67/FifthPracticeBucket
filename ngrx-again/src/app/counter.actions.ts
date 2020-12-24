import { createAction } from "@ngrx/store";

// NgRx actions are like Intents in Android.

export const increment = createAction("Increment");
export const decrement = createAction("Decrement");
export const reset = createAction("Reset");
