import {Action} from '@ngrx/store';

export const INCREMENT = 'INCREMENT';
export const DECREMENT = 'DECREMENT';
export const RESET = 'RESET';

// Notice how the below function name is coupled with app.module.ts.
export function counterReducer(action: Action) {
  var state = 0;
  switch (action.type) {
    case INCREMENT:
      return state + 1;
    case DECREMENT:
      return state - 1;
    case RESET:
      return state;
    default:
      return state;
  }
}