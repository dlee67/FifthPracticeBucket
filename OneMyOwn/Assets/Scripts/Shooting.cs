using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Shooting : MonoBehaviour
{
    public Transform spawnPoint;

    public float fireRate = 1;
    private float lastFireTime = 0;
    
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (Time.time >= lastFireTime + fireRate)
        {
            //Spawn a projectile and mark the time we did it:
            lastFireTime = Time.time;
            Instantiate((GameObject)Resources.Load("../Prefabs/Laser", typeof(GameObject)), spawnPoint.position,spawnPoint.rotation);
        }
    }
}
