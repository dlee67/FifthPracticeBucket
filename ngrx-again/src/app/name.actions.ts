import { createAction, props } from "@ngrx/store";

// https://ngrx.io/guide/store/actions
// Props is required to actually pass something to reducer.
export const saveName = createAction("Save name", props<{name: string}>()); 