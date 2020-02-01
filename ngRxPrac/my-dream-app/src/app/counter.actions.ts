// With the approach I currently have, I don't need an action file.
import { createAction } from '@ngrx/store';

import { INCREMENT, DECREMENT, RESET } from './counter.reducer';

export const increment = createAction(INCREMENT);
export const decrement = createAction(DECREMENT);
export const reset = createAction(RESET);