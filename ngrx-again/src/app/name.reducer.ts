import { createReducer, on } from '@ngrx/store';
import { saveName } from './name.actions'

export const initialName = 'Nemo';

const _nameReducer = createReducer(
    initialName,
    // Whatever content that's within name object gets saved in NgRx store.
    on(saveName, (state, { name }) => name )
);

export function nameReducer(state, action) {
    return _nameReducer(state, action);
}