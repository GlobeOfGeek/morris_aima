#ifndef ENTITY_TESTS
#define ENTITY_TESTS

#include <Agent.h>
#include <Entity.h>
#include "gtest/gtest.h"

class Entity_Tests : public ::testing::Test {
protected:
    virtual void setup() {
    }

    virtual void TearDown() {
        delete a;
    }

    //using agents since I can't test unique ID's using Entity as they are abstract
    Agent *a = new Agent;
    Agent *b = new Agent;
    Agent *c = new Agent;
};

TEST_F(Entity_Tests, unique_id) {
    int origId = a->getId();
    EXPECT_EQ(a->getId(), origId);
    EXPECT_EQ(b->getId(), origId+1);
    EXPECT_EQ(c->getId(), origId+2);
}

#endif