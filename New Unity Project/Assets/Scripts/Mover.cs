using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Mover : MonoBehaviour
{
    public Vector3 direction = Vector3.up;

    float speed = 0.1f;

    void Update()
    {
        var movement = direction * speed;

        // Multiply by delta time; movement now represents 'units per second,'
        // rather than 'units per frame'
        movement *= Time.deltaTime;

        this.transform.Translate(movement);
    }
}