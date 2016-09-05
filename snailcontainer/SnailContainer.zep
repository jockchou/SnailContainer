namespace SnailContainer;

use SnailContainer\Exception\ContainerNotFoundException;

class SnailContainer implements \ArrayAccess, ContainerInterface
{
    private values = [];
    private keys = [];
    private raw = [];
    private frozen = [];
    private factories;
    private protects;
 
    public function __construct(array values = [])
    {
        var key, val;
        
        let this->factories = new \SplObjectStorage();
        let this->protects = new \SplObjectStorage();
        
        
        for key, val in values {
            this->offsetSet(key, val);
        }
    }
    
    public function get(string id)
    {
    
        if !$this->offsetExists(id) {
            throw new ContainerNotFoundException(sprintf("Identifier \"%s\" is not defined.", id));
        }
        
        return this->offsetGet(id);
    }
    
    
    public function has(string id) -> boolean
    {
        return this->offsetExists(id);
    }
    
    
    public function offsetExists(string id) -> boolean
    {
        return isset this->keys[id];
    }
    
    
    public function offsetGet(string id) -> var
    {
        var raw, val;
        
        if !isset this->keys[id] {
            throw new \InvalidArgumentException(sprintf("Identifier \"%s\" is not defined.", id));
        }
        
        if (
            isset this->raw[id]
            || isset this->protects[this->values[id]]
            || !is_object(this->values[id])
            || !method_exists(this->values[id], "__invoke")
        ) {
            return this->values[id];
        }
        
        let raw = this->values[id];
        
        if isset this->factories[raw] {
            return {raw}(this);
        }
        
        let val = {raw}(this);
        let this->values[id] = val;
        let this->raw[id] = raw;
        let this->frozen[id] = true;
        return val;
    }
    
    
    public function offsetSet(string id, var value) -> void
    {
        if isset this->frozen[id] {
            throw new \RuntimeException(sprintf("Cannot override frozen service \"%s\".", id));
        }
        
        let this->values[id] = value;
        let this->keys[id] = true;
    }
    
    
    public function offsetUnset(string id) -> void
    {
    
        if isset this->keys[id] {
            if is_object(this->values[id]) {
                unset(this->protects[this->values[id]]);
                unset(this->factories[this->values[id]]);
            }
            
            unset(this->values[id]);
            unset(this->frozen[id]);
            unset(this->raw[id]);
            unset(this->keys[id]);
        }
    }
    
    
    public function factory(callable callback) -> callable
    {
        if !method_exists(callback, "__invoke") {
            throw new \InvalidArgumentException("Service definition is not a Closure or invokable object.");
        }
        this->factories->attach(callback);
        return callback;
    }
    
    
    public function protect(callable callback)
    {
        if !method_exists(callback, "__invoke") {
            throw new \InvalidArgumentException("Service definition is not a Closure or invokable object.");
        }
        this->protects->attach(callback);
        return callback;
    }
    
    
    public function raw(string id)
    {
        if !isset(this->keys[id]) {
            throw new \InvalidArgumentException(sprintf("Identifier \"%s\" is not defined.", id));
        }
        if isset this->raw[id] {
            return this->raw[id];
        }
        return this->values[id];
    }
    
    
    public function keys() -> array
    {
        return array_keys(this->values);
    }

    
    public function register(<ServiceProviderInterface> provider, array values = []) -> <SnailContainer>
    {
        var key, val;
       
        provider->register(this);
       
        for key, val in values {
            this->offsetSet(key, val);
        }
        
        return this;
    }
}