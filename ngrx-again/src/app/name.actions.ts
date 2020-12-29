import { createAction, props } from "@ngrx/store";

export const saveName = createAction("Save name", props<{Name}>()); 