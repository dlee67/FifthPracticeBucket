package com.oreily.persistence.dao;

import com.oreily.persistence.entities.Officer;
import com.oreily.persistence.entities.Rank;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.test.context.junit.jupiter.SpringExtension;

import javax.transaction.Transactional;

import java.util.List;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.*;

@SuppressWarnings({"SqlNoDataSourceInspection", "SqlResolve"})
@SpringBootTest
@Transactional
@ExtendWith(SpringExtension.class)
public class JpaOfficerDAOTests {
    @Autowired @Qualifier("jpaOfficerDAO")
    private OfficerDAO dao;

    @Autowired
    private JdbcTemplate template;

    private RowMapper<Integer> idMapper = (rs, num) -> rs.getInt("id");

    @Test
    public void testSave() {
        Officer officer = new Officer(Rank.LIEUTENANT, "Nyota", "Uhuru");
        officer = dao.save(officer);
        assertNull(officer.getId());
    }

    @Test
    public void findOneThatExists() {
        template.query("select id from officers", idMapper)
                .forEach(id -> {
                    Optional<Officer> officer = dao.findById(id);
                    assertTrue(officer.isPresent());
                    assertEquals(id, officer.get().getId());
                });
    }

    @Test
    public void count() throws Exception {
        assertEquals(5, dao.count());
    }

    @Test
    public void delete() {
        template.query("select id from officers", idMapper)
                .forEach(id -> {
                    Optional<Officer> officer = dao.findById(id);
                    assertTrue(officer.isPresent());
                    dao.delete(officer.get());
                });
        assertEquals(0, dao.count());
    }

    @Test
    public void existsById() {
        template.query("select id from officers", idMapper)
                .forEach(id -> assertTrue(dao.existsById(id)));
    }

    @Test
    public void doesNotExist() {
        List<Integer> ids = template.query("select id from officers", idMapper);
        assertFalse(dao.existsById(999));
    }
}