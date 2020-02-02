import {Action} from '@ngrx/store';

export const NAME = 'NAME';

// Notice how the below function name is coupled with app.module.ts.
export function nameReducer(state, action: Action) {
  switch (action.type) {
    case NAME:
      return 'some Name';
    default:
      return 'no name';
  }
}