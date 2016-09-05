namespace SnailContainer;

/**
 * Snail service provider interface.
 *
 */
interface ServiceProviderInterface
{
    /**
     * Registers services on the given container.
     *
     * This method should only be used to configure services and parameters.
     * It should not get services.
     *
     * @param container A SnailContainer instance
     */
    public function register(<SnailContainer> container);
}