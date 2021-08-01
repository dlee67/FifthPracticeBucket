using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace WebApplication1
{
    public class CustomLogger
    {
        private readonly RequestDelegate _next;

        public CustomLogger(RequestDelegate next)
        {
            _next = next ?? throw new ArgumentNullException(nameof(next));
        }

        public async Task Invoke(HttpContext httpContext)
        {
            if (httpContext == null) throw new
            ArgumentNullException(nameof(httpContext));

            // TODO - log the request

            await _next(httpContext);

            // TODO - log the response 
        }
    }

    public static class MiddlewareExtensions
    {
        // The UseMiddleware method in IApplicationBuilder is used to register the middleware class.
        // The middleware will now be available in an instance of IApplicationBuilder in a method called UseCustomLogger.
        public static IApplicationBuilder UseCustomLogger(this
        IApplicationBuilder app)
        {
            return app.UseMiddleware<CustomLogger>();
        }
    }
}
