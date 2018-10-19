#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform sampler2D texture;

varying vec2 v_texcoord;
varying vec3 v_color;

//! [0]
void main()
{
    // Set fragment color from texture
    //gl_FragColor = texture2D(texture, v_texcoord);
    //float ambientStrength = 0.5;
    //vec3 ambient = ambientStrength * lightColor;

    vec3 result = v_color;

    gl_FragColor = vec4(result, 1.0);
}
//! [0]

