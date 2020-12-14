using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooting : MonoBehaviour
{
    public Transform spawnPoint;
    public GameObject laser; // Defined in the Unity inspector

    public Vector3 forceVector = new Vector3(1, 0, 0);

    public float fireRate = 1;
    private float lastFireTime = 0;
    
    // Start is called before the first frame update
    void Start()
    {
        spawnPoint = transform;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.X) && (Time.time >= lastFireTime + fireRate))
        {
            //Spawn a projectile and mark the time we did it:
            lastFireTime = Time.time;
            laser.GetComponent<Rigidbody>().velocity = forceVector * 100000000 * 10000000;
            Instantiate(laser, spawnPoint.position,spawnPoint.rotation);
        }
    }
}
