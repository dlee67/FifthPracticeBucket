using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooting : MonoBehaviour
{
    public Transform spawnPoint;
    public GameObject laser; // Defined in the Unity inspector

    public GameObject bullet;
    public float bulletSpeed = 100f;
    
    // Start is called before the first frame update
    void Start()
    {
        spawnPoint = transform;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            //Spawn a projectile and mark the time we did it:
            GameObject allyProjectile = Instantiate(laser,
                this.transform.position + new Vector3(0, 0, 0),
                   this.transform.rotation) as GameObject;

            Rigidbody bulletRigidBody = allyProjectile.GetComponent<Rigidbody>();

            bulletRigidBody.velocity = this.transform.forward * bulletSpeed * -1;
        }
    }
}
