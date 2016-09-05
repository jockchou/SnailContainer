namespace SnailContainer\Exception;

use RuntimeException;
/**
 * No entry was found in the container.
 */
class ContainerNotFoundException extends \RuntimeException implements ContainerException
{

}