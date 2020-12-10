using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float moveSpeed = 10f;
    public float rotateSpeed = 75f;
    public float jumpForce = 100.0f;
    public bool isGrounded;
    private float vInput;
    private float hInput;

    private Rigidbody rb;
    public Vector3 jump;

    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody>();
        jump = new Vector3(0.0f, 10.0f, 0.0f);
    }

    void OnCollisionStay()
    {
        isGrounded = true;
    }

    void OnTriggerEnter(Collider other) {
        Debug.Log("Player collided with an object");
        if (other.gameObject.layer.Equals("Platform")) {
            Debug.Log("Collided with a Platform layer");
            this.transform.parent = other.gameObject.transform;
        }
    }

    void OnTriggerExit(Collider other)
    {
        Debug.Log("Leaving an object");
        // if (other.gameObject.layer.Equals("Platform")) {
        this.transform.parent = null;
        // }
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Space) && isGrounded){
     
            rb.AddForce(jump * jumpForce, ForceMode.Impulse);
            isGrounded = false;
        }

        vInput = Input.GetAxis("Vertical") * moveSpeed;
        hInput = Input.GetAxis("Horizontal") * rotateSpeed;

        this.transform.Translate(Vector3.forward*vInput*Time.deltaTime);
        this.transform.Rotate(Vector3.up*hInput*Time.deltaTime);
    }
}