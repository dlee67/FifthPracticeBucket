import { createReducer, on } from '@ngrx/store';
import { increment, decrement, reset } from './counter.actions';

export const initialState = 0;

// Reducers are like a braodcast receiver in Android, but with a mechanism that
// they also have the instructions on what to do with the states, and they hold the states at the sametime.
// Essentially, reducers ARE states.

const _counterReducer = createReducer(
  initialState,
  on(increment, (state) => state + 1),
  on(decrement, (state) => state - 1),
  on(reset, (state) => 0)
);

export function counterReducer(state, action) {
  return _counterReducer(state, action);
}