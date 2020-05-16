import React, {userEffect, useState, useContext, useRef} from 'react';
import {Text, FlatList, Touchable} from 'react-native';

import PropTypes from 'prop-types';
import {Button} from 'native-base';
import {Layout} from '../Components/Layout';
import {NoteContent} from '../Components/NoteContent';
import {NoteContext} from '../Context/NodeContext';
import { TouchableOpacity } from 'react-native-gesture-handler';
import { withNavigationFocus } from 'react-navigation';

const HomeScreen = props => {
    const prevProps = useRef(false);
    const { getContextNotes } = userContext(NoteContext);
    const [notes, setNotes] = useState();

    userEffect(() => {
        const getData = () => {
            if(prevProps.isFocused !== props.isFocused) {
                const getNotes = getContextNotes();
                setNotes(getNotes);
            }
        };
        getData();
    }, [getContextNotes, props.isFocused]);

    return (
        <Layout
            title='My Notes'
            footer={
                <Button full onPress={() => props.navigation.navigate('AddNoteScreen')}>
                    <Text>Add Note</Text>
                </Button>
            }
        >
        <FlatList
            data={notes}
            keyExtractor={note => note.id}
            renderItem={note=>(
                <TouchableOpacity
                    onPress={
                        () =>
                        props.navigation.navigate('ModNote', {
                            id: note.item.id,
                        })
                    }>
                    <NoteContent note={{...note}}/>
                </TouchableOpacity>
            )}
        />        
        </Layout>
    );
}

export default withNavigationFocus(HomeScreen);