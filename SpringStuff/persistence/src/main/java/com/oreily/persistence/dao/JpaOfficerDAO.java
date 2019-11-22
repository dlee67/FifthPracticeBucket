package com.oreily.persistence.dao;

import com.oreily.persistence.entities.Officer;
import com.oreily.persistence.entities.Rank;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.jdbc.core.simple.SimpleJdbcInsert;
import org.springframework.stereotype.Repository;

import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import java.util.List;
import java.util.Optional;

@SuppressWarnings("JpaQlInspection")
@Repository
public class JpaOfficerDAO implements OfficerDAO {

    @PersistenceContext
    private EntityManager entityManager;

    private JdbcTemplate jdbcTemplate;
    private SimpleJdbcInsert insertOfficer;

    private RowMapper<Officer> officerMapper =
            ((rs, rowNum) -> new Officer(rs.getInt("id"),
                                        Rank.valueOf(rs.getString("rank")),
                                        rs.getString("first_name"),
                                        rs.getString("last_name")));

    @Override
    public Officer save(Officer officer) {
        entityManager.persist(officer);
        return officer;
    }

    @Override
    public Optional<Officer> findById(Integer id) {
        return Optional.ofNullable(entityManager.find(Officer.class, id));
    }

    @Override
    public List<Officer> findAll() {
        return entityManager.createQuery("select o from Officer o", Officer.class).getResultList();
    }

    @Override
    public long count() {
        return entityManager.createQuery("select count(o.id) from Officer o", Long.class).getSingleResult() ;
    }

    @Override
    public void delete(Officer officer) {
        entityManager.remove(officer);
    }

    @Override
    public boolean existsById(Integer id) {
        Long count = entityManager.createQuery("select count(o.id) from Officer o where o.id=:id", Long.class)
                .setParameter("id", id)
                .getSingleResult();
        return count > 0;
    }
}
